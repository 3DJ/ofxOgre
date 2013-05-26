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
#define P_EMBER3LIFE 2.0

//The vertex shader that prepares the fireworks for display
// ColoredFirework DisplayParticles_VS
// (
//     in vec3 		inPos : POSITION,
// 	in float 		inTimer : TEXCOORD0,
// 	in float 		inType : TEXCOORD1,
// 	in vec3 		inVelocity : TEXCOORD2
// 	
// 
//     //uniform mat4 worldViewProj
// )
void main()
{
	ColoredFirework output;
    //
    // Pass the point through
    //
    output.pos = inPos; //Multiply by world matrix?
    output.radius = 1.5;
    
    //  
    // calculate the color
    //
    if( inType == PT_LAUNCHER )
    {
        output.color = vec4(1,0.1,0.1,1);
        output.radius = 1.0;
    }
    else if( inType == PT_SHELL )
    {
        output.color = vec4(0.1,1,1,1);
        output.radius = 1.0;
    }
    else if( inType == PT_EMBER1 )
    {
        output.color = vec4(1,1,0.1,1);
        output.color *= (inTimer / P_EMBER1LIFE );
    }
    else if( inType == PT_EMBER2 )
    {
        output.color = vec4(1,0.1,1,1);
    }
    else if( inType == PT_EMBER3 )
    {
        output.color = vec4(1,0.1,0.1,1);
        output.color *= (inTimer / P_EMBER3LIFE );
    }
    
    return output;
}
