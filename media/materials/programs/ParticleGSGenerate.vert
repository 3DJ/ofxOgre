in vec4 		inPos : POSITION,	
in float 		inTimer : TEXCOORD0,
in float 		inType : TEXCOORD1,
in vec3 		inVelocity : TEXCOORD2

struct FireworkData
{
	vec4 	Pos 	: POSITION;
	float 	Timer 	: TEXCOORD0;
    float 	Type 	: TEXCOORD1;
	vec3	Velocity : TEXCOORD2;
};

//The vertex shader that prepares the fireworks for display
// FireworkData GenerateParticles_VS(
//     in vec4 		inPos : POSITION,	
// 	in float 		inTimer : TEXCOORD0,
// 	in float 		inType : TEXCOORD1,
// 	in vec3 		inVelocity : TEXCOORD2
// 	)
void main()
{
	FireworkData output;
	output.Pos = inPos;
	output.Timer = inTimer;
	output.Type = inType;
	output.Velocity = inVelocity;
	gl_Position = inPos;

	return output;
}
