//
// Explanation of different particle types
//
#define PT_LAUNCHER 0 //Firework Launcher - launches a PT_SHELL every so many seconds
#define PT_SHELL    1 //Unexploded shell - flies from the origin and explodes into many PT_EMBERXs
#define PT_EMBER1   2 //basic particle - after it's emitted from the shell, it dies
#define PT_EMBER2   3 //after it's emitted, it explodes again into many PT_EMBER1s
#define PT_EMBER3   4 //just a differently colored ember1
#define P_SHELLLIFE 3.0
#define P_EMBER1LIFE 2.5
#define P_EMBER2LIFE 1.5
#define P_EMBER3LIFE 2.0

//These two were originally shader params, but they caused runtime errors
#define NUM_EMBER_1S 30
#define NUM_EMBER_2S 15
#define NUM_EMBER_3S 10
//This one was originally a variant, but this also causes runtime errors
//#define MAX_EMBER_2S 15.0

//
// Generic particle motion handler
//

void GSGenericHandler( vec3 Pos, vec3 Vel, float Timer, float Type,
						float elapsedTime, 
						vec3 frameGravity)
{
    Pos += Vel * elapsedTime;
    Vel += frameGravity;
    Timer -= elapsedTime;
	if (Pos.y > -100)
	{
		emitVertex( Pos : POSITION, Vel : TEXCOORD2, Timer : TEXCOORD0, Type : TEXCOORD1);
	}
}

//
// Sample a random direction from our random texture
//
vec3 RandomDir(float fOffset, float globalTime, sampler1D randomTex)
{
    float tCoord = (globalTime + fOffset) / 300.0;
    return tex1D(randomTex, tCoord).rgb;
}

//
// Launcher type particle handler
//
void GSLauncherHandler( vec3 Pos, vec3 Vel, float Timer, float Type, 
						float elapsedTime, 
						float globalTime, 
						sampler1D randomTex,
						float secondsPerFirework)
{
    if(Timer <= 0)
    {
        vec3 vRandom = normalize( RandomDir( Type, globalTime, randomTex) );
		//Give it more of an up bias
        vRandom = normalize(vRandom + vec3(0,2.5,0)); 
		
		//time to emit a new SHELL
        vec3 outputPos = Pos + Vel*elapsedTime;
        vec3 outputVel = Vel + vRandom*35.0;
        float  outputTimer = P_SHELLLIFE + vRandom.y*0.5;
        float outputType = PT_SHELL;
        emitVertex(outputPos : POSITION, outputVel : TEXCOORD2, outputTimer : TEXCOORD0, outputType : TEXCOORD1);
        
        //reset our timer
        Timer = secondsPerFirework + vRandom.x*0.4;
    }
    else
    {
        Timer -= elapsedTime;
    }
    
    //emit ourselves to keep us alive
    emitVertex( Pos : POSITION, Vel : TEXCOORD2, Timer : TEXCOORD0, Type : TEXCOORD1);
}

//
// Shell type particle handler
//	
void GSShellHandler( vec3 Pos, vec3 Vel, float Timer, float Type,
					float elapsedTime, 
					float globalTime, 
					sampler1D randomTex,
					vec3 frameGravity)
{
    if(Timer <= 0)
    {
        vec3 outputPos;
		vec3 outputVel;
		float outputTimer;
		float outputType;
		
        vec3 vRandom = vec3(0,0,0);
        
        //time to emit a series of new Ember1s  
        for(int i=0; i<NUM_EMBER_1S; i++)
        {
            vRandom = normalize( RandomDir( Type+i, globalTime, randomTex ) );
            outputPos = Pos + Vel*elapsedTime;
            outputVel = Vel + vRandom*15.0;
            outputTimer = P_EMBER1LIFE;
            outputType = PT_EMBER1;
            emitVertex(outputPos : POSITION, outputTimer : TEXCOORD0, outputType : TEXCOORD1, outputVel : TEXCOORD2);
        }
        
        //find out how many Ember2s to emit
		//Not doing this because it causes a runtime error
		//int numEmber2s = abs(vRandom.x)*MAX_EMBER_2S;
        for(int i=0; i<NUM_EMBER_2S; i++)
        {
            vRandom = normalize( RandomDir( Type, globalTime, randomTex) );
            outputPos = Pos + Vel*elapsedTime;
            outputVel = Vel + vRandom*10.0;
            outputTimer = P_EMBER2LIFE + 0.4*vRandom.x;
            outputType = PT_EMBER2;
            emitVertex(outputPos : POSITION, outputVel : TEXCOORD2, outputTimer : TEXCOORD0, outputType : TEXCOORD1);
        }
        
    }
    else
    {
        GSGenericHandler(Pos, Vel, Timer, Type, elapsedTime, frameGravity );
    }
}

//
// Ember1 and Ember3 type particle handler
//
void GSEmber1Handler( vec3 Pos, vec3 Vel, float Timer, float Type,
						float elapsedTime, 
						vec3 frameGravity)
{
    if(Timer > 0)
    {
        GSGenericHandler(Pos, Vel, Timer, Type, elapsedTime, frameGravity );
    }
}

//
// Ember2 type particle handler
//
void GSEmber2Handler( vec3 Pos, vec3 Vel, float Timer, float Type,
						float elapsedTime, 
						float globalTime, 
						sampler1D randomTex,
						vec3 frameGravity)
{
    if(Timer <= 0)
    {
		vec3 outputPos;
		vec3 outputVel;
		float outputTimer;
		float outputType;
    
        //time to emit a series of new Ember3s  
        for(int i=0; i<NUM_EMBER_3S; i++)
        {
            outputPos = Pos + Vel*elapsedTime;
            outputVel = Vel + normalize( RandomDir( Type + i, globalTime, randomTex ) )*10.0;
            outputTimer = P_EMBER3LIFE;
            outputType = PT_EMBER3;
            emitVertex(outputPos : POSITION, outputVel : TEXCOORD2, outputTimer : TEXCOORD0, outputType : TEXCOORD1);
        }
    }
    else
    {
         GSGenericHandler(Pos, Vel, Timer, Type, elapsedTime, frameGravity );
    }
}


// void GenerateParticles_GS(
// 	AttribArray<vec3> Pos : POSITION,
// 	AttribArray<float> Timer : TEXCOORD0,
// 	AttribArray<float> Type : TEXCOORD1,
// 	AttribArray<vec3> Vel : TEXCOORD2,
// 	
// 	uniform sampler1D randomTex : TEXUNIT0,
// 	uniform vec3 frameGravity,
// 	uniform float globalTime,
// 	uniform float elapsedTime,
// 	uniform float secondsPerFirework
// 	)
void main()
{
	if( Type[0] == PT_LAUNCHER )
        GSLauncherHandler( Pos[0], Vel[0], Timer[0], Type[0], 
							elapsedTime, globalTime, randomTex, secondsPerFirework);
	else if ( Type[0] == PT_SHELL )
        GSShellHandler( Pos[0], Vel[0], Timer[0], Type[0], 
							elapsedTime, globalTime, randomTex, frameGravity);
	else if ( Type[0] == PT_EMBER1 ||
              Type[0] == PT_EMBER3 )
       GSEmber1Handler( Pos[0], Vel[0], Timer[0], Type[0], 
							elapsedTime, frameGravity);
    else if( Type[0] == PT_EMBER2 )
        GSEmber2Handler( Pos[0], Vel[0], Timer[0], Type[0], 
							elapsedTime, globalTime, randomTex, frameGravity);
}
