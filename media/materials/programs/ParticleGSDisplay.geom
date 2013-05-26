uniform mat4 inverseView;
uniform mat4 worldViewProj;

attribute vec3 Pos : POSITION,
attribute vec4 Color : COLOR,
AttribArray<float> Radius : TEXCOORD0,

void main()
//The geometry shader that prepares the fireworks for display
// void DisplayParticles_GS( AttribArray<vec3> Pos : POSITION,
// 							AttribArray<vec4> Color : COLOR,
// 							AttribArray<float> Radius : TEXCOORD0,
// 							
// 							uniform vec4x4 inverseView,
// 							uniform vec4x4 worldViewProj)
{
	//vec3 g_positions[4] = { vec3( -1, 1, 0 ), vec3( 1, 1, 0 ), vec3( -1, -1, 0 ), vec3( 1, -1, 0 ) };
	vec3 g_positions[4] = { vec3( -1, 1, 0 ), vec3( -1, -1, 0 ), vec3( 1, 1, 0 ), vec3( 1, -1, 0 ) };
    vec2 g_texcoords[4] = { vec2(0,1), vec2(1,1), vec2(0,0), vec2(1,0) };
	
	
	//
    // Emit two new triangles
    //
    for(int i=0; i<4; i++)
    {
		vec3 position = -g_positions[i]*Radius[0];
        position = (mat3)inverseView * position + Pos[0];
        vec4 outPos = worldViewProj * vec4(position, 1.0);
        
        EmitVertex(outPos : POSITION, Color[0] : COLOR0, g_texcoords[i] : TEXCOORD0);
    }
    restartStrip();
}
