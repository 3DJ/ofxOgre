varying vec2 iTexCoord;
varying vec4 iColor;
uniform sampler2D diffuseTex;

//The pixels shaders that colors the fireworks
// float4 DisplayParticles_PS(	float2 iTexCoord : TEXCOORD0,
// 							float4 iColor : COLOR0,
// 							uniform sampler diffuseTex : register(s0)) : COLOR
void main()
{
	gl_FragColor = texture2D(diffuseTex, iTexCoord) * iColor;
	//return float4(iTexCoord.x, iTexCoord.y, 0, 1) + iColor * 0.01;
	//return float4(iTexCoord.xy, 0, 1) * 0.3 + tex2D(diffuseTex, iTexCoord) * 0.7 + iColor * 0.01;
}