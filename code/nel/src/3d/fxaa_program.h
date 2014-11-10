
const char *a_nelvp =
	"!!VP1.0\n"
	"DP4 o[HPOS].x, c[0], v[OPOS];\n"
	"DP4 o[HPOS].y, c[1], v[OPOS];\n"
	"DP4 o[HPOS].z, c[2], v[OPOS];\n"
	"DP4 o[HPOS].w, c[3], v[OPOS];\n"
	"MOV o[TEX0].xy, v[TEX0];\n"
	// "ADD o[TEX1], v[TEX0].xyxy, c[9];\n"
	"END\n";

const char *a_arbfp1_test =
	"!!ARBfp1.0\n"
	"OPTION ARB_precision_hint_fastest;\n"
	"TEX result.color, fragment.texcoord[1].zwzw, texture[0], 2D;\n"
	"END\n";

const char *a_arbfp1 =
	"!!ARBfp1.0\n"
	"OPTION ARB_precision_hint_fastest;\n"
	/*"# cgc version 3.1.0013, build date Apr 18 2012\n"
	"# command line args: -profile arbfp1 -O3 -fastmath -fastprecision\n"
	"# source file: fxaa_pp.cg\n"
	"#vendor NVIDIA Corporation\n"
	"#version 3.1.0.13\n"
	"#profile arbfp1\n"
	"#program fxaa_pp\n"
	"#semantic fxaa_pp.fxaaQualityRcpFrame\n"
	"#semantic fxaa_pp.fxaaQualitySubpix\n"
	"#semantic fxaa_pp.fxaaQualityEdgeThreshold\n"
	"#semantic fxaa_pp.fxaaQualityEdgeThresholdMin\n"
	"#semantic fxaa_pp.nlTex0 : TEX0\n"
	"#var float2 pos : $vin.TEXCOORD0 : TEX0 : 0 : 1\n"
	"#var float2 fxaaQualityRcpFrame :  : c[0] : 2 : 1\n"
	"#var float fxaaQualitySubpix :  : c[1] : 3 : 1\n"
	"#var float fxaaQualityEdgeThreshold :  : c[2] : 4 : 1\n"
	"#var float fxaaQualityEdgeThresholdMin :  : c[3] : 5 : 1\n"
	"#var sampler2D nlTex0 : TEX0 : texunit 0 : 6 : 1\n"
	"#var float4 oCol : $vout.COLOR : COL : 7 : 1\n"
	"#const c[4] = 0 -1 1 -2\n"
	"#const c[5] = 2 0.5 0.25 1.5\n"
	"#const c[6] = 4 12 0.083333336 3\n"*/
	"PARAM c[7] = { program.env[0..3],\n"
	"		{ 0, -1, 1, -2 },\n"
	"		{ 2, 0.5, 0.25, 1.5 },\n"
	"		{ 4, 12, 0.083333336, 3 } };\n"
	"TEMP R0;\n"
	"TEMP R1;\n"
	"TEMP R2;\n"
	"TEMP R3;\n"
	"TEMP R4;\n"
	"TEMP R5;\n"
	"TEMP R6;\n"
	"TEMP R7;\n"
	"TEMP R8;\n"
	"TEMP R9;\n"
	"MOV R3.xyz, c[4];\n"
	"MAD R2.zw, R3.xyyz, c[0].xyxy, fragment.texcoord[0].xyxy;\n"
	"MAD R0.xy, R3, c[0], fragment.texcoord[0];\n"
	"MAD R1.xy, R3.zyzw, c[0], fragment.texcoord[0];\n"
	"TEX R5.y, R1, texture[0], 2D;\n"
	"MAD R1.xy, R3.zxzw, c[0], fragment.texcoord[0];\n"
	"ADD R0.zw, fragment.texcoord[0].xyxy, -c[0].xyxy;\n"
	"TEX R4.y, R0.zwzw, texture[0], 2D;\n"
	"TEX R6.y, R2.zwzw, texture[0], 2D;\n"
	"TEX R8, fragment.texcoord[0], texture[0], 2D;\n"
	"TEX R1.y, R1, texture[0], 2D;\n"
	"TEX R0.y, R0, texture[0], 2D;\n"
	"ADD R0.z, R4.y, R5.y;\n"
	"MAD R1.z, R0.y, c[4].w, R0;\n"
	"MAD R0.zw, R3.xyyx, c[0].xyxy, fragment.texcoord[0].xyxy;\n"
	"TEX R2.y, R0.zwzw, texture[0], 2D;\n"
	"ADD R0.x, R2.y, R1.y;\n"
	"ABS R0.w, R1.z;\n"
	"ADD R1.zw, fragment.texcoord[0].xyxy, c[0].xyxy;\n"
	"TEX R7.y, R1.zwzw, texture[0], 2D;\n"
	"MAD R0.z, R8.y, c[4].w, R0.x;\n"
	"ABS R0.z, R0;\n"
	"MAD R2.x, R0.z, c[5], R0.w;\n"
	"MAD R0.zw, R3.xyxz, c[0].xyxy, fragment.texcoord[0].xyxy;\n"
	"TEX R3.y, R0.zwzw, texture[0], 2D;\n"
	"ADD R0.z, R0.y, R3.y;\n"
	"ADD R1.x, R6.y, R7.y;\n"
	"MAD R0.w, R3.y, c[4], R1.x;\n"
	"MAD R1.x, R8.y, c[4].w, R0.z;\n"
	"ABS R0.w, R0;\n"
	"ADD R2.x, R0.w, R2;\n"
	"ADD R2.w, R4.y, R6.y;\n"
	"ADD R0.w, R5.y, R7.y;\n"
	"ABS R1.z, R1.x;\n"
	"MAD R1.x, R1.y, c[4].w, R0.w;\n"
	"ABS R1.w, R1.x;\n"
	"MAD R1.x, R2.y, c[4].w, R2.w;\n"
	"MAD R1.z, R1, c[5].x, R1.w;\n"
	"ABS R1.x, R1;\n"
	"ADD R1.x, R1, R1.z;\n"
	"SGE R4.x, R1, R2;\n"
	"MAX R1.x, R3.y, R8.y;\n"
	"MAX R1.z, R1.y, R1.x;\n"
	"MAX R1.x, R0.y, R2.y;\n"
	"MAX R1.x, R1, R1.z;\n"
	"MIN R1.z, R3.y, R8.y;\n"
	"MIN R1.w, R1.y, R1.z;\n"
	"MIN R1.z, R0.y, R2.y;\n"
	"MIN R1.z, R1, R1.w;\n"
	"MUL R2.x, R1, c[2];\n"
	"ADD R3.z, R1.x, -R1;\n"
	"ABS R3.w, R4.x;\n"
	"MAX R1.w, R2.x, c[3].x;\n"
	"ADD R2.z, R3, -R1.w;\n"
	"CMP R2.x, R2.z, c[4], c[4].z;\n"
	"CMP R1.x, -R3.w, c[4], c[4].z;\n"
	"MUL R3.w, R2.x, R1.x;\n"
	"CMP R1.z, -R3.w, R1.y, R3.y;\n"
	"ADD R1.y, -R8, R1.z;\n"
	"CMP R1.w, -R3, R2.y, R0.y;\n"
	"ADD R0.y, -R8, R1.w;\n"
	"MUL R4.x, R2, R4;\n"
	"CMP R3.y, -R3.w, c[0], R3.x;\n"
	"ABS R4.w, R1.y;\n"
	"ABS R4.z, R0.y;\n"
	"SGE R0.y, R4.z, R4.w;\n"
	"MUL R1.y, R2.x, R0;\n"
	"ABS R0.y, R0;\n"
	"CMP R4.y, -R0, c[4].x, c[4].z;\n"
	"ABS R0.y, R1.x;\n"
	"CMP R0.y, -R0, c[4].x, c[4].z;\n"
	"MUL R1.x, R2, R0.y;\n"
	"CMP R2.y, -R4.x, c[0], c[0].x;\n"
	"CMP R2.y, -R1, -R2, R2;\n"
	"MAD R1.y, R2, c[5], fragment.texcoord[0];\n"
	"CMP R5.z, -R4.x, R1.y, fragment.texcoord[0].y;\n"
	"ADD R5.y, R5.z, -R3;\n"
	"MAD R0.y, R2, c[5], fragment.texcoord[0].x;\n"
	"CMP R3.x, -R1, c[0], R3;\n"
	"CMP R6.x, -R3.w, R0.y, fragment.texcoord[0];\n"
	"ADD R5.w, R5.z, R3.y;\n"
	"ADD R1.x, R6, -R3;\n"
	"MOV R1.y, R5;\n"
	"TEX R0.y, R1, texture[0], 2D;\n"
	"MUL R1.y, R2.x, R4;\n"
	"ADD R0.x, R0.z, R0;\n"
	"ADD R0.w, R2, R0;\n"
	"MAD R0.z, R0.x, c[5].x, R0.w;\n"
	"ADD R1.w, R8.y, R1;\n"
	"ADD R1.z, R8.y, R1;\n"
	"CMP R4.y, -R1, R1.z, R1.w;\n"
	"ADD R1.z, R6.x, R3.x;\n"
	"MAD R5.x, -R4.y, c[5].y, R0.y;\n"
	"MOV R1.w, R5;\n"
	"TEX R0.y, R1.zwzw, texture[0], 2D;\n"
	"MAX R1.w, R4.z, R4;\n"
	"MAD R1.y, -R4, c[5], R0;\n"
	"MUL R4.z, R1.w, c[5];\n"
	"ABS R0.y, R1;\n"
	"SGE R1.w, R0.y, R4.z;\n"
	"ABS R6.y, R5.x;\n"
	"SGE R0.y, R6, R4.z;\n"
	"ABS R1.w, R1;\n"
	"CMP R6.y, -R1.w, c[4].x, c[4].z;\n"
	"ABS R0.y, R0;\n"
	"CMP R5.z, -R0.y, c[4].x, c[4];\n"
	"ADD_SAT R0.y, R5.z, R6;\n"
	"MUL R4.w, R2.x, R0.y;\n"
	"MUL R0.y, R2.x, R6;\n"
	"MAD R1.w, R3.y, c[5], R5;\n"
	"CMP R6.x, -R0.y, R1.w, R5.w;\n"
	"MAD R6.z, R3.x, c[5].w, R1;\n"
	"CMP R1.z, -R0.y, R6, R1;\n"
	"MOV R1.w, R6.x;\n"
	"TEX R0.y, R1.zwzw, texture[0], 2D;\n"
	"MUL R1.w, R4, R6.y;\n"
	"CMP R6.y, -R1.w, R0, R1;\n"
	"MUL R0.y, R2.x, R5.z;\n"
	"MAD R1.y, -R3, c[5].w, R5;\n"
	"CMP R5.w, -R0.y, R1.y, R5.y;\n"
	"MAD R6.z, -R3.x, c[5].w, R1.x;\n"
	"CMP R1.x, -R0.y, R6.z, R1;\n"
	"MOV R1.y, R5.w;\n"
	"TEX R0.y, R1, texture[0], 2D;\n"
	"MUL R5.y, R4.w, R5.z;\n"
	"CMP R0.y, -R5, R0, R5.x;\n"
	"MAD R5.x, -R4.y, c[5].y, R0.y;\n"
	"CMP R5.z, -R5.y, R5.x, R0.y;\n"
	"MAD R1.y, -R4, c[5], R6;\n"
	"CMP R1.y, -R1.w, R1, R6;\n"
	"ABS R1.w, R1.y;\n"
	"SGE R1.w, R1, R4.z;\n"
	"ABS R0.y, R5.z;\n"
	"SGE R0.y, R0, R4.z;\n"
	"ABS R1.w, R1;\n"
	"CMP R6.y, -R1.w, c[4].x, c[4].z;\n"
	"ABS R0.y, R0;\n"
	"CMP R5.y, -R0, c[4].x, c[4].z;\n"
	"ADD_SAT R0.y, R5, R6;\n"
	"MUL R5.x, R4.w, R0.y;\n"
	"MUL R0.y, R4.w, R6;\n"
	"MAD R1.w, R3.y, c[5].x, R6.x;\n"
	"CMP R6.x, -R0.y, R1.w, R6;\n"
	"MAD R6.z, R3.x, c[5].x, R1;\n"
	"CMP R1.z, -R0.y, R6, R1;\n"
	"MOV R1.w, R6.x;\n"
	"TEX R0.y, R1.zwzw, texture[0], 2D;\n"
	"MUL R1.w, R5.x, R6.y;\n"
	"CMP R6.y, -R1.w, R0, R1;\n"
	"MUL R0.y, R4.w, R5;\n"
	"MAD R1.y, -R3, c[5].x, R5.w;\n"
	"CMP R4.w, -R0.y, R1.y, R5;\n"
	"MAD R6.z, -R3.x, c[5].x, R1.x;\n"
	"CMP R1.x, -R0.y, R6.z, R1;\n"
	"MOV R1.y, R4.w;\n"
	"TEX R0.y, R1, texture[0], 2D;\n"
	"MUL R5.y, R5.x, R5;\n"
	"CMP R0.y, -R5, R0, R5.z;\n"
	"MAD R5.z, -R4.y, c[5].y, R0.y;\n"
	"CMP R5.w, -R5.y, R5.z, R0.y;\n"
	"MAD R1.y, -R4, c[5], R6;\n"
	"CMP R1.y, -R1.w, R1, R6;\n"
	"ABS R1.w, R1.y;\n"
	"SGE R1.w, R1, R4.z;\n"
	"ABS R1.w, R1;\n"
	"CMP R6.y, -R1.w, c[4].x, c[4].z;\n"
	"ABS R0.y, R5.w;\n"
	"SGE R0.y, R0, R4.z;\n"
	"ABS R0.y, R0;\n"
	"CMP R5.y, -R0, c[4].x, c[4].z;\n"
	"ADD_SAT R0.y, R5, R6;\n"
	"MUL R5.z, R5.x, R0.y;\n"
	"MUL R0.y, R5.x, R6;\n"
	"MAD R1.w, R3.y, c[6].x, R6.x;\n"
	"CMP R6.x, -R0.y, R1.w, R6;\n"
	"MAD R6.z, R3.x, c[6].x, R1;\n"
	"CMP R1.z, -R0.y, R6, R1;\n"
	"MOV R1.w, R6.x;\n"
	"TEX R0.y, R1.zwzw, texture[0], 2D;\n"
	"MUL R1.w, R5.z, R6.y;\n"
	"CMP R6.y, -R1.w, R0, R1;\n"
	"MUL R0.y, R5.x, R5;\n"
	"MAD R1.y, -R3, c[6].x, R4.w;\n"
	"CMP R4.w, -R0.y, R1.y, R4;\n"
	"MAD R5.x, -R3, c[6], R1;\n"
	"CMP R1.x, -R0.y, R5, R1;\n"
	"MOV R1.y, R4.w;\n"
	"TEX R0.y, R1, texture[0], 2D;\n"
	"MUL R1.y, R5.z, R5;\n"
	"CMP R5.x, -R1.y, R0.y, R5.w;\n"
	"MAD R5.y, -R4, c[5], R5.x;\n"
	"CMP R1.y, -R1, R5, R5.x;\n"
	"MAD R0.y, -R4, c[5], R6;\n"
	"CMP R0.y, -R1.w, R0, R6;\n"
	"ABS R5.x, R0.y;\n"
	"ABS R1.w, R1.y;\n"
	"SGE R1.w, R1, R4.z;\n"
	"SGE R5.x, R5, R4.z;\n"
	"ABS R4.z, R5.x;\n"
	"ABS R1.w, R1;\n"
	"CMP R4.z, -R4, c[4].x, c[4];\n"
	"CMP R1.w, -R1, c[4].x, c[4].z;\n"
	"MUL R4.z, R5, R4;\n"
	"MAD R5.y, R3.x, c[6], R1.z;\n"
	"CMP R5.y, -R4.z, R5, R1.z;\n"
	"MAD R5.x, R3.y, c[6].y, R6;\n"
	"CMP R1.z, -R4, R5.x, R6.x;\n"
	"MUL R1.w, R5.z, R1;\n"
	"ADD R4.z, -fragment.texcoord[0].x, R5.y;\n"
	"ADD R1.z, -fragment.texcoord[0].y, R1;\n"
	"CMP R1.z, -R3.w, R1, R4;\n"
	"MAD R4.z, -R3.x, c[6].y, R1.x;\n"
	"MAD R3.x, -R3.y, c[6].y, R4.w;\n"
	"CMP R3.y, -R1.w, R4.z, R1.x;\n"
	"CMP R1.x, -R1.w, R3, R4.w;\n"
	"ADD R1.w, fragment.texcoord[0].x, -R3.y;\n"
	"ADD R1.x, fragment.texcoord[0].y, -R1;\n"
	"CMP R1.x, -R3.w, R1, R1.w;\n"
	"SLT R1.w, R1.x, R1.z;\n"
	"ADD R3.x, R1, R1.z;\n"
	"ABS R1.w, R1;\n"
	"MIN R1.x, R1, R1.z;\n"
	"CMP R1.w, -R1, c[4].x, c[4].z;\n"
	"MUL R1.z, R2.x, R1.w;\n"
	"RCP R3.x, R3.x;\n"
	"MAD R1.x, R1, -R3, c[5].y;\n"
	"MUL R1.w, R4.y, c[5].y;\n"
	"SLT R3.x, R1.y, c[4];\n"
	"SLT R1.y, R8, R1.w;\n"
	"SLT R0.y, R0, c[4].x;\n"
	"ADD R0.y, R0, -R1;\n"
	"ADD R1.y, -R1, R3.x;\n"
	"ABS R0.y, R0;\n"
	"ABS R1.y, R1;\n"
	"CMP R0.y, -R0, c[4].z, c[4].x;\n"
	"CMP R1.y, -R1, c[4].z, c[4].x;\n"
	"CMP R0.x, -R1.z, R0.y, R1.y;\n"
	"MAD R0.y, R0.z, c[6].z, -R8;\n"
	"ABS R0.x, R0;\n"
	"CMP R0.x, -R0, c[4], c[4].z;\n"
	"MUL R0.x, R2, R0;\n"
	"CMP R0.x, -R0, c[4], R1;\n"
	"RCP R0.z, R3.z;\n"
	"ABS R0.y, R0;\n"
	"MUL_SAT R0.y, R0, R0.z;\n"
	"MUL R0.z, R0.y, c[4].w;\n"
	"ADD R0.z, R0, c[6].w;\n"
	"MUL R0.y, R0, R0;\n"
	"MUL R0.y, R0.z, R0;\n"
	"MUL R0.y, R0, R0;\n"
	"MUL R0.y, R0, c[1].x;\n"
	"MAX R0.x, R0, R0.y;\n"
	"MAD R0.y, R0.x, R2, fragment.texcoord[0];\n"
	"MAD R0.z, R0.x, R2.y, fragment.texcoord[0].x;\n"
	"CMP R0.x, -R3.w, R0.z, fragment.texcoord[0];\n"
	"CMP R0.y, -R4.x, R0, fragment.texcoord[0];\n"
	"TEX R0.xyz, R0, texture[0], 2D;\n"
	"CMP R1, R2.z, R8, R9;\n"
	"MOV R0.w, R8.y;\n"
	"CMP result.color, -R2.x, R0, R1;\n"
	"END\n";
	/*"# 260 instructions, 10 R-regs\n"
	"\n"*/

const char *a_arbfp1_ps3 = 
	"!!ARBfp1.0\n"
	"OPTION ARB_precision_hint_fastest;\n"
	//# cgc version 3.1.0013, build date Apr 18 2012
	//# command line args: -profile arbfp1 -O3 -fastmath -fastprecision
	//# source file: fxaa_fp.cg
	//#vendor NVIDIA Corporation
	//#version 3.1.0.13
	//#profile arbfp1
	//#program fxaa_fp
	//#semantic fxaa_fp.fxaaConsoleRcpFrameOpt
	//#semantic fxaa_fp.fxaaConsoleRcpFrameOpt2
	//#semantic fxaa_fp.nlTex0 : TEX0
	//#var float2 pos : $vin.TEXCOORD0 : TEX0 : 0 : 1
	//#var float4 fxaaConsolePosPos : $vin.TEXCOORD1 : TEX1 : 1 : 1
	//#var float4 fxaaConsoleRcpFrameOpt :  : c[0] : 2 : 1
	//#var float4 fxaaConsoleRcpFrameOpt2 :  : c[1] : 3 : 1
	//#var sampler2D nlTex0 : TEX0 : texunit 0 : 4 : 1
	//#var float4 oCol : $vout.COLOR : COL : 5 : 1
	//#const c[2] = 0.125 0 -2 2
	//#const c[3] = 0.001953125 0.5
	"PARAM c[4] = { program.env[0..1],\n"
	"		{ 0.125, 0, -2, 2 },\n"
	"		{ 0.001953125, 0.5 } };\n"
	"TEMP R0;\n"
	"TEMP R1;\n"
	"TEMP R2;\n"
	"TEMP R3;\n"
	"TEMP R4;\n"
	"TEMP R5;\n"
	"TEX R1.w, fragment.texcoord[1].zyzw, texture[0], 2D;\n"
	"ADD R0.x, R1.w, c[3];\n"
	"TEX R0.w, fragment.texcoord[1].xwzw, texture[0], 2D;\n"
	"TEX R1.w, fragment.texcoord[1], texture[0], 2D;\n"
	"ADD R0.y, -R0.x, R0.w;\n"
	"ADD R0.z, R1.w, R0.y;\n"
	"TEX R2.w, fragment.texcoord[1].zwzw, texture[0], 2D;\n"
	"ADD R0.y, -R1.w, R0;\n"
	"ADD R1.x, R2.w, R0.y;\n"
	"ADD R1.y, R0.z, -R2.w;\n"
	"MUL R2.xy, R1, R1;\n"
	"ADD R0.y, R2.x, R2;\n"
	"RSQ R0.y, R0.y;\n"
	"MUL R2.xy, R0.y, R1;\n"
	"MAD R3.xy, R2, c[0].zwzw, fragment.texcoord[0];\n"
	"ABS R0.z, R2.y;\n"
	"ABS R0.y, R2.x;\n"
	"MIN R0.y, R0, R0.z;\n"
	"RCP R0.y, R0.y;\n"
	"MUL R1.xy, R0.y, R2;\n"
	"MUL R1.xy, R1, c[2].x;\n"
	"MIN R1.xy, R1, c[2].w;\n"
	"TEX R4, R3, texture[0], 2D;\n"
	"MAD R2.xy, -R2, c[0].zwzw, fragment.texcoord[0];\n"
	"TEX R3, R2, texture[0], 2D;\n"
	"ADD R3, R3, R4;\n"
	"MAX R1.xy, R1, c[2].z;\n"
	"MAD R2.xy, R1, c[1].zwzw, fragment.texcoord[0];\n"
	"MUL R5, R3, c[3].y;\n"
	"MAD R1.xy, -R1, c[1].zwzw, fragment.texcoord[0];\n"
	"MIN R0.z, R0.x, R2.w;\n"
	"MIN R0.y, R0.w, R1.w;\n"
	"MIN R0.y, R0, R0.z;\n"
	"MAX R0.z, R0.x, R2.w;\n"
	"MAX R0.x, R0.w, R1.w;\n"
	"MAX R0.x, R0, R0.z;\n"
	"TEX R4, R2, texture[0], 2D;\n"
	"TEX R3, R1, texture[0], 2D;\n"
	"ADD R3, R3, R4;\n"
	"MAD R3, R3, c[3].y, R5;\n"
	"MUL R3, R3, c[3].y;\n"
	"SLT R0.z, R0.x, R3.w;\n"
	"SLT R0.x, R3.w, R0.y;\n"
	"ADD_SAT R0.x, R0, R0.z;\n"
	"CMP result.color, -R0.x, R5, R3;\n"
	"END\n";
	//# 45 instructions, 6 R-regs

const char *a_arbfp1_earlyexit = 
	"!!ARBfp1.0\n"
	"OPTION ARB_precision_hint_fastest;\n"
	//"# cgc version 3.1.0013, build date Apr 18 2012\n"
	//"# command line args: -profile arbfp1\n"
	//"# source file: fxaa_fp.cg\n"
	//"#vendor NVIDIA Corporation\n"
	//"#version 3.1.0.13\n"
	//"#profile arbfp1\n"
	//"#program fxaa_fp\n"
	//"#semantic fxaa_fp.fxaaConsoleRcpFrameOpt\n"
	//"#semantic fxaa_fp.fxaaConsoleRcpFrameOpt2\n"
	//"#semantic fxaa_fp.nlTex0 : TEX0\n"
	//"#var float2 pos : $vin.TEXCOORD0 : TEX0 : 0 : 1\n"
	//"#var float4 fxaaConsolePosPos : $vin.TEXCOORD1 : TEX1 : 1 : 1\n"
	//"#var float4 fxaaConsoleRcpFrameOpt :  : c[0] : 2 : 1\n"
	//"#var float4 fxaaConsoleRcpFrameOpt2 :  : c[1] : 3 : 1\n"
	//"#var sampler2D nlTex0 : TEX0 : texunit 0 : 4 : 1\n"
	//"#var float4 oCol : $vout.COLOR : COL : 5 : 1\n"
	//"#const c[2] = 0.125 0 8 0.001953125\n"
	//"#const c[3] = -2 2 0.5\n"
	"PARAM c[4] = { program.env[0..1],\n"
	"		{ 0.125, 0, 8, 0.001953125 },\n"
	"		{ -2, 2, 0.5 } };\n"
	"TEMP R0;\n"
	"TEMP R1;\n"
	"TEMP R2;\n"
	"TEMP R3;\n"
	"TEMP R4;\n"
	"TEMP R5;\n"
	"TEX R0.w, fragment.texcoord[1].zyzw, texture[0], 2D;\n"
	"ADD R0.x, R0.w, c[2].w;\n"
	"TEX R1.w, fragment.texcoord[1].xwzw, texture[0], 2D;\n"
	"TEX R0.w, fragment.texcoord[1], texture[0], 2D;\n"
	"ADD R0.y, R1.w, -R0.x;\n"
	"ADD R0.z, R0.w, R0.y;\n"
	"TEX R2.w, fragment.texcoord[1].zwzw, texture[0], 2D;\n"
	"ADD R0.y, -R0.w, R0;\n"
	"ADD R1.z, -R2.w, R0;\n"
	"ADD R1.x, R2.w, R0.y;\n"
	"MOV R1.y, c[2];\n"
	"DP3 R0.y, R1, R1;\n"
	"RSQ R0.y, R0.y;\n"
	"MUL R2.xy, R0.y, R1.xzzw;\n"
	"MAD R3.xy, R2, c[0].zwzw, fragment.texcoord[0];\n"
	"ABS R0.z, R2.y;\n"
	"ABS R0.y, R2.x;\n"
	"MIN R0.y, R0, R0.z;\n"
	"RCP R0.y, R0.y;\n"
	"MUL R1.xy, R0.y, R2;\n"
	"MUL R1.xy, R1, c[2].x;\n"
	"MIN R1.xy, R1, c[3].y;\n"
	"MIN R0.y, R0.w, R1.w;\n"
	"TEX R4, R3, texture[0], 2D;\n"
	"MAD R2.xy, -R2, c[0].zwzw, fragment.texcoord[0];\n"
	"TEX R3, R2, texture[0], 2D;\n"
	"ADD R3, R3, R4;\n"
	"MAX R1.xy, R1, c[3].x;\n"
	"MAD R2.xy, R1, c[1].zwzw, fragment.texcoord[0];\n"
	"MAD R1.xy, -R1, c[1].zwzw, fragment.texcoord[0];\n"
	"MUL R5, R3, c[3].z;\n"
	"TEX R4, R2, texture[0], 2D;\n"
	"TEX R3, R1, texture[0], 2D;\n"
	"MIN R0.z, R0.x, R2.w;\n"
	"MIN R1.x, R0.y, R0.z;\n"
	"MAX R0.y, R0.x, R2.w;\n"
	"MAX R0.x, R0.w, R1.w;\n"
	"MAX R2.x, R0, R0.y;\n"
	"ADD R3, R3, R4;\n"
	"MAD R3, R3, c[3].z, R5;\n"
	"MUL R3, R3, c[3].z;\n"
	"SLT R1.z, R2.x, R3.w;\n"
	"SLT R1.y, R3.w, R1.x;\n"
	"TEX R0, fragment.texcoord[0], texture[0], 2D;\n"
	"ADD_SAT R1.y, R1, R1.z;\n"
	"MIN R1.z, R0.w, R1.x;\n"
	"MAX R1.x, R2, R0.w;\n"
	"ADD R2.y, R1.x, -R1.z;\n"
	"CMP R1, -R1.y, R5, R3;\n"
	"MAD R2.x, R2.y, c[2].z, -R2;\n"
	"CMP result.color, R2.x, R0, R1;\n"
	"END\n";
	//"# 51 instructions, 6 R-regs\n"

const char *a_ps_2_0_test_t0 =
	"ps_2_x\n"
	"dcl_2d s0\n"
	"dcl t0.xyz\n"
	"mov r0.xy, t0.xy\n"
	"texld r0, r0, s0\n"
	"mov oC0, r0\n";

const char *a_ps_2_0_test_avg = 
	"ps_2_x\n"
	"dcl_2d s0\n"
	"def c0, 0.25000000, 0, 0, 0\n"
	"dcl t1\n"
	"mov r0.xy, t1.xwzw\n"
	"mov r1.xy, t1.zyzw\n"
	"texld r0, r0, s0\n"
	"texld r1, r1, s0\n"
	"add r2, r1, r0\n"
	"mov r0.xy, t1.zwzw\n"
	"texld r1, t1, s0\n"
	"texld r0, r0, s0\n"
	"add r1, r2, r1\n"
	"add r0, r1, r0\n"
	"mul r0, r0, c0.x\n"
	"mov oC0, r0\n";

const char *a_ps_2_0 =
	"ps_2_x\n"
	/*"// cgc version 3.1.0013, build date Apr 18 2012\n"
	"// command line args: -profile ps_2_x -O3 -fastmath -fastprecision\n"
	"// source file: fxaa_pp.cg\n"
	"//vendor NVIDIA Corporation\n"
	"//version 3.1.0.13\n"
	"//profile ps_2_x\n"
	"//program fxaa_pp\n"
	"//semantic fxaa_pp.fxaaQualityRcpFrame\n"
	"//semantic fxaa_pp.fxaaQualitySubpix\n"
	"//semantic fxaa_pp.fxaaQualityEdgeThreshold\n"
	"//semantic fxaa_pp.fxaaQualityEdgeThresholdMin\n"
	"//semantic fxaa_pp.nlTex0 : TEX0\n"
	"//var float2 pos : $vin.TEXCOORD0 : TEX0 : 0 : 1\n"
	"//var float2 fxaaQualityRcpFrame :  : c[0] : 2 : 1\n"
	"//var float fxaaQualitySubpix :  : c[1] : 3 : 1\n"
	"//var float fxaaQualityEdgeThreshold :  : c[2] : 4 : 1\n"
	"//var float fxaaQualityEdgeThresholdMin :  : c[3] : 5 : 1\n"
	"//var sampler2D nlTex0 : TEX0 : texunit 0 : 6 : 1\n"
	"//var float4 oCol : $vout.COLOR : COL : 7 : 1\n"
	"//const c[4] = 0 -1 1 -2\n"
	"//const c[5] = 2 0.5 0.25 1.5\n"
	"//const c[6] = 4 12 0.083333336\n"
	"//const c[7] = -2 3\n"*/
	"dcl_2d s0\n"
	"def c4, 0.00000000, -1.00000000, 1.00000000, -2.00000000\n"
	"def c5, 2.00000000, 0.50000000, 0.25000000, 1.50000000\n"
	"def c6, 4.00000000, 12.00000000, 0.08333334, 0\n"
	"def c7, -2.00000000, 3.00000000, 0, 0\n"
	"dcl t0.xy\n"
	"mov r0.zw, c0.xyxy\n"
	"mad r3.xy, c4.zxzw, r0.zwzw, t0\n"
	"texld r7, r3, s0\n"
	"texld r1, t0, s0\n"
	"mov r0.xy, c0\n"
	"mad r0.xy, c4.yxzw, r0, t0\n"
	"texld r8, r0, s0\n"
	"mov r0.xy, c0\n"
	"mad r0.xy, c4, r0, t0\n"
	"texld r9, r0, s0\n"
	"add r0.xy, t0, -c0\n"
	"texld r5, r0, s0\n"
	"mov r3.xy, c0\n"
	"mad r3.xy, c4.zyzw, r3, t0\n"
	"texld r3, r3, s0\n"
	"add r7.x, r8.y, r7.y\n"
	"mad r0.z, r1.y, c4.w, r7.x\n"
	"add r0.x, r5.y, r3.y\n"
	"mad r0.w, r9.y, c4, r0.x\n"
	"mov r0.xy, c0\n"
	"mad r0.xy, c4.xzzw, r0, t0\n"
	"texld r6, r0, s0\n"
	"add r5.x, r9.y, r6.y\n"
	"abs r0.z, r0\n"
	"abs r0.w, r0\n"
	"mad r3.x, r0.z, c5, r0.w\n"
	"mov r0.zw, c0.xyxy\n"
	"mad r4.xy, c4.yzzw, r0.zwzw, t0\n"
	"texld r4, r4, s0\n"
	"add r0.xy, t0, c0\n"
	"texld r0, r0, s0\n"
	"add r4.x, r5.y, r4.y\n"
	"add r5.y, r3, r0\n"
	"add r0.x, r4.y, r0.y\n"
	"mad r0.x, r6.y, c4.w, r0\n"
	"abs r0.x, r0\n"
	"add r0.w, r0.x, r3.x\n"
	"mad r0.x, r8.y, c4.w, r4\n"
	"mad r0.z, r7.y, c4.w, r5.y\n"
	"mad r0.y, r1, c4.w, r5.x\n"
	"abs r0.z, r0\n"
	"abs r0.y, r0\n"
	"mad r0.y, r0, c5.x, r0.z\n"
	"abs r0.x, r0\n"
	"add r0.x, r0, r0.y\n"
	"add r0.x, r0, -r0.w\n"
	"cmp r3.y, r0.x, c4.z, c4.x\n"
	"max r0.y, r6, r1\n"
	"max r0.z, r7.y, r0.y\n"
	"max r0.y, r9, r8\n"
	"max r0.y, r0, r0.z\n"
	"min r0.z, r6.y, r1.y\n"
	"min r0.w, r7.y, r0.z\n"
	"min r0.z, r9.y, r8.y\n"
	"min r0.z, r0, r0.w\n"
	"mul r3.x, r0.y, c2\n"
	"abs_pp r0.x, r3.y\n"
	"add r4.y, r0, -r0.z\n"
	"max r0.w, r3.x, c3.x\n"
	"add r4.z, r4.y, -r0.w\n"
	"cmp_pp r4.w, r4.z, c4.z, c4.x\n"
	"mul_pp r5.w, r4, r3.y\n"
	"cmp_pp r0.y, -r0.x, c4.z, c4.x\n"
	"mul_pp r5.z, r4.w, r0.y\n"
	"cmp_pp r3.x, -r0, c4, c4.z\n"
	"cmp r6.w, -r5.z, r6.y, r7.y\n"
	"cmp r7.w, -r5.z, r9.y, r8.y\n"
	"add r0.z, -r1.y, r6.w\n"
	"add r0.y, -r1, r7.w\n"
	"abs r9.z, r0\n"
	"abs r7.y, r0\n"
	"add r0.y, r7, -r9.z\n"
	"cmp r0.y, r0, c4.z, c4.x\n"
	"max r7.y, r7, r9.z\n"
	"mul_pp r0.z, r4.w, r0.y\n"
	"cmp r0.w, -r5, c0.x, c0.y\n"
	"cmp r6.x, -r0.z, r0.w, -r0.w\n"
	"mov r0.z, c0.y\n"
	"cmp r6.y, -r5.z, c4.x, r0.z\n"
	"mad r0.w, r6.x, c5.y, t0.y\n"
	"cmp r0.z, -r5.w, t0.y, r0.w\n"
	"add r8.z, r0, r6.y\n"
	"add r7.z, r0, -r6.y\n"
	"mov r9.y, r7.z\n"
	"mov r8.y, r8.z\n"
	"mad r0.w, r6.x, c5.y, t0.x\n"
	"mov r0.x, c0\n"
	"mul_pp r3.x, r4.w, r3\n"
	"cmp r6.z, -r3.x, c4.x, r0.x\n"
	"cmp r0.x, -r5.z, t0, r0.w\n"
	"add r9.x, r0, -r6.z\n"
	"texld r3, r9, s0\n"
	"add r8.x, r0, r6.z\n"
	"abs_pp r3.x, r0.y\n"
	"texld r0, r8, s0\n"
	"cmp_pp r0.x, -r3, c4.z, c4\n"
	"add r0.w, r1.y, r6\n"
	"add r0.z, r1.y, r7.w\n"
	"mul_pp r0.x, r4.w, r0\n"
	"cmp r6.w, -r0.x, r0.z, r0\n"
	"mad r7.w, -r6, c5.y, r0.y\n"
	"mad r8.w, -r6, c5.y, r3.y\n"
	"abs r0.y, r7.w\n"
	"abs r0.x, r8.w\n"
	"mad r0.x, -r7.y, c5.z, r0\n"
	"mad r0.y, -r7, c5.z, r0\n"
	"cmp r0.x, r0, c4.z, c4\n"
	"abs_pp r0.x, r0\n"
	"cmp_pp r9.z, -r0.x, c4, c4.x\n"
	"cmp r0.y, r0, c4.z, c4.x\n"
	"abs_pp r0.y, r0\n"
	"cmp_pp r9.w, -r0.y, c4.z, c4.x\n"
	"mul_pp r0.x, r4.w, r9.z\n"
	"mad r0.y, -r6, c5.w, r7.z\n"
	"cmp r7.z, -r0.x, r7, r0.y\n"
	"mad r0.z, -r6, c5.w, r9.x\n"
	"cmp r9.x, -r0, r9, r0.z\n"
	"mov r9.y, r7.z\n"
	"texld r3, r9, s0\n"
	"add_pp_sat r3.z, r9, r9.w\n"
	"mul_pp r0.x, r4.w, r9.w\n"
	"mad r0.y, r6, c5.w, r8.z\n"
	"cmp r3.x, -r0, r8.z, r0.y\n"
	"mad r0.z, r6, c5.w, r8.x\n"
	"mul_pp r8.z, r4.w, r3\n"
	"cmp r8.x, -r0, r8, r0.z\n"
	"mov r8.y, r3.x\n"
	"texld r0, r8, s0\n"
	"mul_pp r0.w, r8.z, r9\n"
	"cmp r3.z, -r0.w, r7.w, r0.y\n"
	"mul_pp r0.x, r8.z, r9.z\n"
	"cmp r0.y, -r0.x, r8.w, r3\n"
	"mad r0.z, -r6.w, c5.y, r0.y\n"
	"cmp r8.w, -r0.x, r0.y, r0.z\n"
	"mad r3.y, -r6.w, c5, r3.z\n"
	"cmp r9.w, -r0, r3.z, r3.y\n"
	"abs r0.y, r9.w\n"
	"abs r0.x, r8.w\n"
	"mad r0.y, -r7, c5.z, r0\n"
	"mad r0.x, -r7.y, c5.z, r0\n"
	"cmp r0.y, r0, c4.z, c4.x\n"
	"abs_pp r0.y, r0\n"
	"cmp_pp r10.x, -r0.y, c4.z, c4\n"
	"cmp r0.x, r0, c4.z, c4\n"
	"abs_pp r0.x, r0\n"
	"cmp_pp r9.z, -r0.x, c4, c4.x\n"
	"mul_pp r0.x, r8.z, r10\n"
	"mad r0.y, r6, c5.x, r3.x\n"
	"cmp r7.w, -r0.x, r3.x, r0.y\n"
	"mad r0.z, r6, c5.x, r8.x\n"
	"cmp r8.x, -r0, r8, r0.z\n"
	"mov r8.y, r7.w\n"
	"texld r0, r8, s0\n"
	"mul_pp r0.w, r8.z, r9.z\n"
	"mad r3.x, -r6.z, c5, r9\n"
	"mad r0.x, -r6.y, c5, r7.z\n"
	"cmp r0.x, -r0.w, r7.z, r0\n"
	"add_pp_sat r0.z, r9, r10.x\n"
	"mul_pp r7.z, r8, r0\n"
	"cmp r9.x, -r0.w, r9, r3\n"
	"mov r9.y, r0.x\n"
	"texld r3, r9, s0\n"
	"mul_pp r0.z, r7, r9\n"
	"cmp r0.w, -r0.z, r8, r3.y\n"
	"mul_pp r3.x, r7.z, r10\n"
	"cmp r3.y, -r3.x, r9.w, r0\n"
	"mad r0.y, -r6.w, c5, r0.w\n"
	"cmp r8.z, -r0, r0.w, r0.y\n"
	"mad r3.z, -r6.w, c5.y, r3.y\n"
	"cmp r9.z, -r3.x, r3.y, r3\n"
	"abs r0.y, r8.z\n"
	"abs r0.z, r9\n"
	"mad r0.y, -r7, c5.z, r0\n"
	"mad r0.z, -r7.y, c5, r0\n"
	"cmp r0.y, r0, c4.z, c4.x\n"
	"abs_pp r0.y, r0\n"
	"cmp_pp r8.w, -r0.y, c4.z, c4.x\n"
	"cmp r0.z, r0, c4, c4.x\n"
	"abs_pp r0.z, r0\n"
	"cmp_pp r9.w, -r0.z, c4.z, c4.x\n"
	"mul_pp r0.y, r7.z, r8.w\n"
	"mad r0.z, -r6.y, c6.x, r0.x\n"
	"cmp r10.x, -r0.y, r0, r0.z\n"
	"mad r0.w, -r6.z, c6.x, r9.x\n"
	"cmp r9.x, -r0.y, r9, r0.w\n"
	"mov r9.y, r10.x\n"
	"texld r3, r9, s0\n"
	"mul_pp r0.x, r7.z, r9.w\n"
	"mad r0.z, r6, c6.x, r8.x\n"
	"mad r0.y, r6, c6.x, r7.w\n"
	"cmp r3.x, -r0, r7.w, r0.y\n"
	"cmp r8.x, -r0, r8, r0.z\n"
	"mov r8.y, r3.x\n"
	"texld r0, r8, s0\n"
	"add_pp_sat r3.z, r8.w, r9.w\n"
	"mul_pp r0.x, r7.z, r3.z\n"
	"mul_pp r3.z, r0.x, r9.w\n"
	"cmp r0.y, -r3.z, r9.z, r0\n"
	"mul_pp r0.z, r0.x, r8.w\n"
	"cmp r0.w, -r0.z, r8.z, r3.y\n"
	"mad r3.w, -r6, c5.y, r0.y\n"
	"cmp r0.y, -r3.z, r0, r3.w\n"
	"mad r3.y, -r6.w, c5, r0.w\n"
	"cmp r0.z, -r0, r0.w, r3.y\n"
	"abs r3.y, r0\n"
	"abs r0.w, r0.z\n"
	"mad r3.y, -r7, c5.z, r3\n"
	"mad r0.w, -r7.y, c5.z, r0\n"
	"cmp r3.y, r3, c4.z, c4.x\n"
	"abs_pp r3.y, r3\n"
	"cmp r0.w, r0, c4.z, c4.x\n"
	"cmp_pp r3.z, -r3.y, c4, c4.x\n"
	"abs_pp r0.w, r0\n"
	"cmp_pp r3.y, -r0.w, c4.z, c4.x\n"
	"mul_pp r0.w, r0.x, r3.z\n"
	"mul_pp r0.x, r0, r3.y\n"
	"mad r3.w, r6.y, c6.y, r3.x\n"
	"cmp r3.x, -r0.w, r3, r3.w\n"
	"mad r3.z, r6, c6.y, r8.x\n"
	"cmp r0.w, -r0, r8.x, r3.z\n"
	"mad r3.y, -r6, c6, r10.x\n"
	"cmp r3.y, -r0.x, r10.x, r3\n"
	"add r3.x, -t0.y, r3\n"
	"add r0.w, -t0.x, r0\n"
	"cmp r0.w, -r5.z, r0, r3.x\n"
	"mad r3.x, -r6.z, c6.y, r9\n"
	"cmp r0.x, -r0, r9, r3\n"
	"add r3.x, t0.y, -r3.y\n"
	"add r0.x, t0, -r0\n"
	"cmp r0.x, -r5.z, r0, r3\n"
	"add r3.x, r0, -r0.w\n"
	"add r3.y, r0.x, r0.w\n"
	"cmp r3.x, r3, c4, c4.z\n"
	"abs_pp r3.x, r3\n"
	"min r0.x, r0, r0.w\n"
	"cmp_pp r3.x, -r3, c4.z, c4\n"
	"mul_pp r0.w, r4, r3.x\n"
	"rcp r3.y, r3.y\n"
	"mad r0.x, r0, -r3.y, c5.y\n"
	"cmp r3.y, r0, c4.x, c4.z\n"
	"mad r3.x, -r6.w, c5.y, r1.y\n"
	"cmp r3.x, r3, c4, c4.z\n"
	"cmp r0.y, r0.z, c4.x, c4.z\n"
	"add_pp r0.z, -r3.x, r3.y\n"
	"add_pp r0.y, r0, -r3.x\n"
	"abs_pp r0.y, r0\n"
	"abs_pp r0.z, r0\n"
	"cmp_pp r0.z, -r0, c4.x, c4\n"
	"cmp_pp r0.y, -r0, c4.x, c4.z\n"
	"cmp_pp r0.y, -r0.w, r0, r0.z\n"
	"abs_pp r0.y, r0\n"
	"cmp_pp r0.y, -r0, c4.z, c4.x\n"
	"mul_pp r0.y, r4.w, r0\n"
	"rcp r0.w, r4.y\n"
	"cmp r0.x, -r0.y, r0, c4\n"
	"add r3.y, r4.x, r5\n"
	"add r3.x, r5, r7\n"
	"mad r3.x, r3, c5, r3.y\n"
	"mad r0.z, r3.x, c6, -r1.y\n"
	"abs r0.z, r0\n"
	"mul_sat r0.z, r0, r0.w\n"
	"mul r0.w, r0.z, r0.z\n"
	"mad r0.z, r0, c7.x, c7.y\n"
	"mul r0.z, r0, r0.w\n"
	"mul r0.z, r0, r0\n"
	"mul r0.z, r0, c1.x\n"
	"max r0.x, r0, r0.z\n"
	"mad r0.y, r0.x, r6.x, t0\n"
	"mad r0.z, r0.x, r6.x, t0.x\n"
	"cmp r0.x, -r5.z, t0, r0.z\n"
	"cmp r0.y, -r5.w, t0, r0\n"
	"texld r0, r0, s0\n"
	"mov r0.w, r1.y\n"
	"cmp r1, r4.z, r2, r1\n"
	"cmp r0, -r4.w, r1, r0\n"
	"mov oC0, r0\n";

const char *a_ps_2_0_ps3 = 
	"ps_2_0\n"
	// cgc version 3.1.0013, build date Apr 18 2012
	// command line args: -profile ps_2_0 -O3 -fastmath -fastprecision
	// source file: fxaa_pp.cg
	//vendor NVIDIA Corporation
	//version 3.1.0.13
	//profile ps_2_0
	//program fxaa_pp
	//semantic fxaa_pp.fxaaConsoleRcpFrameOpt
	//semantic fxaa_pp.fxaaConsoleRcpFrameOpt2
	//semantic fxaa_pp.nlTex0 : TEX0
	//var float2 pos : $vin.TEXCOORD0 : TEX0 : 0 : 1
	//var float4 fxaaConsolePosPos : $vin.TEXCOORD1 : TEX1 : 1 : 1
	//var float4 fxaaConsoleRcpFrameOpt :  : c[0] : 2 : 1
	//var float4 fxaaConsoleRcpFrameOpt2 :  : c[1] : 3 : 1
	//var sampler2D nlTex0 : TEX0 : texunit 0 : 4 : 1
	//var float4 oCol : $vout.COLOR : COL : 5 : 1
	//const c[2] = 0.001953125 0.125 2 -2
	//const c[3] = 0.5 0 1
	"dcl_2d s0\n"
	"def c2, 0.00195313, 0.12500000, 2.00000000, -2.00000000\n"
	"def c3, 0.50000000, 0.00000000, 1.00000000, 0\n"
	"dcl t1\n"
	"dcl t0.xy\n"
	"texld r5, t1, s0\n"
	"mov r1.y, t1.w\n"
	"mov r1.x, t1.z\n"
	"mov r2.xy, r1\n"
	"mov r0.y, t1.w\n"
	"mov r0.x, t1\n"
	"mov r1.y, t1\n"
	"mov r1.x, t1.z\n"
	"texld r1, r1, s0\n"
	"texld r0, r0, s0\n"
	"texld r6, r2, s0\n"
	"add r0.x, r1.w, c2\n"
	"add r2.x, -r0, r0.w\n"
	"add r1.x, r5.w, r2\n"
	"add r2.z, r1.x, -r6.w\n"
	"add r2.x, -r5.w, r2\n"
	"add r2.x, r6.w, r2\n"
	"mov r3.x, r2\n"
	"mov r3.y, r2.z\n"
	"mov r2.y, r2.z\n"
	"mov r1.y, r2.z\n"
	"mov r1.x, r2\n"
	"mul r1.xy, r3, r1\n"
	"add r1.x, r1, r1.y\n"
	"rsq r1.x, r1.x\n"
	"mul r4.xy, r1.x, r2\n"
	"abs r2.x, r4.y\n"
	"abs r1.x, r4\n"
	"min r1.x, r1, r2\n"
	"rcp r1.x, r1.x\n"
	"mul r1.xy, r1.x, r4\n"
	"mul r1.xy, r1, c2.y\n"
	"min r1.xy, r1, c2.z\n"
	"max r2.xy, r1, c2.w\n"
	"mov r1.y, c1.w\n"
	"mov r1.x, c1.z\n"
	"mad r3.xy, r2, r1, t0\n"
	"mov r1.y, c1.w\n"
	"mov r1.x, c1.z\n"
	"mad r5.xy, -r2, r1, t0\n"
	"mov r1.y, c0.w\n"
	"mov r1.x, c0.z\n"
	"mad r2.xy, -r4, r1, t0\n"
	"mov r1.y, c0.w\n"
	"mov r1.x, c0.z\n"
	"mad r1.xy, r4, r1, t0\n"
	"texld r4, r5, s0\n"
	"texld r3, r3, s0\n"
	"texld r1, r1, s0\n"
	"texld r2, r2, s0\n"
	"add r1, r2, r1\n"
	"mul r2, r1, c3.x\n"
	"add r1, r4, r3\n"
	"max r3.x, r0, r6.w\n"
	"mad r1, r1, c3.x, r2\n"
	"mul r4, r1, c3.x\n"
	"max r1.x, r0.w, r5.w\n"
	"max r1.x, r1, r3\n"
	"add r1.x, -r4.w, r1\n"
	"min r3.x, r0.w, r5.w\n"
	"min r0.x, r0, r6.w\n"
	"min r0.x, r3, r0\n"
	"add r0.x, r4.w, -r0\n"
	"cmp r1.x, r1, c3.y, c3.z\n"
	"cmp r0.x, r0, c3.y, c3.z\n"
	"add_pp_sat r0.x, r0, r1\n"
	"cmp r0, -r0.x, r4, r2\n"
	"mov oC0, r0\n";

const char *a_ps_2_0_earlyexit = 
	"ps_2_x\n"
	// cgc version 3.1.0013, build date Apr 18 2012
	// command line args: -profile ps_2_x
	// source file: fxaa_fp.cg
	//vendor NVIDIA Corporation
	//version 3.1.0.13
	//profile ps_2_x
	//program fxaa_fp
	//semantic fxaa_fp.fxaaConsoleRcpFrameOpt
	//semantic fxaa_fp.fxaaConsoleRcpFrameOpt2
	//semantic fxaa_fp.nlTex0 : TEX0
	//var float2 pos : $vin.TEXCOORD0 : TEX0 : 0 : 1
	//var float4 fxaaConsolePosPos : $vin.TEXCOORD1 : TEX1 : 1 : 1
	//var float4 fxaaConsoleRcpFrameOpt :  : c[0] : 2 : 1
	//var float4 fxaaConsoleRcpFrameOpt2 :  : c[1] : 3 : 1
	//var sampler2D nlTex0 : TEX0 : texunit 0 : 4 : 1
	//var float4 oCol : $vout.COLOR : COL : 5 : 1
	//const c[2] = 0.001953125 0 0.125 2
	//const c[3] = -2 0.5 0 1
	//const c[4] = 8
	"dcl_2d s0\n"
	"def c2, 0.00195313, 0.00000000, 0.12500000, 2.00000000\n"
	"def c3, -2.00000000, 0.50000000, 0.00000000, 1.00000000\n"
	"def c4, 8.00000000, 0, 0, 0\n"
	"dcl t1\n"
	"dcl t0.xy\n"
	"mov r0.xy, t1.zyzw\n"
	"texld r0, r0, s0\n"
	"mov r0.xy, t1.xwzw\n"
	"texld r5, t1, s0\n"
	"texld r4, r0, s0\n"
	"add r4.x, r0.w, c2\n"
	"mov r0.xy, t1.zwzw\n"
	"texld r3, r0, s0\n"
	"add r0.w, r4, -r4.x\n"
	"add r0.x, r5.w, r0.w\n"
	"add r0.z, -r3.w, r0.x\n"
	"add r0.x, -r5.w, r0.w\n"
	"add r0.x, r3.w, r0\n"
	"mov r0.y, c2\n"
	"dp3 r0.y, r0, r0\n"
	"rsq r0.y, r0.y\n"
	"mul r0.zw, r0.y, r0.xyxz\n"
	"mad r1.xy, -r0.zwzw, c0.zwzw, t0\n"
	"texld r1, r1, s0\n"
	"abs r0.y, r0.w\n"
	"abs r0.x, r0.z\n"
	"min r0.x, r0, r0.y\n"
	"rcp r0.x, r0.x\n"
	"mul r0.xy, r0.x, r0.zwzw\n"
	"mul r0.xy, r0, c2.z\n"
	"min r2.xy, r0, c2.w\n"
	"mad r0.xy, r0.zwzw, c0.zwzw, t0\n"
	"texld r0, r0, s0\n"
	"add r0, r1, r0\n"
	"max r1.xy, r2, c3.x\n"
	"mul r2, r0, c3.y\n"
	"mad r0.xy, r1, c1.zwzw, t0\n"
	"mad r1.xy, -r1, c1.zwzw, t0\n"
	"texld r0, r0, s0\n"
	"texld r1, r1, s0\n"
	"add r0, r1, r0\n"
	"mad r0, r0, c3.y, r2\n"
	"mul r1, r0, c3.y\n"
	"min r0.y, r4.x, r3.w\n"
	"min r0.x, r5.w, r4.w\n"
	"min r3.y, r0.x, r0\n"
	"add r0.x, -r3.y, r1.w\n"
	"max r0.z, r4.x, r3.w\n"
	"max r0.y, r5.w, r4.w\n"
	"max r3.x, r0.y, r0.z\n"
	"cmp r3.z, r0.x, c3, c3.w\n"
	"add r3.w, r3.x, -r1\n"
	"cmp r3.w, r3, c3.z, c3\n"
	"add_pp_sat r3.z, r3, r3.w\n"
	"texld r0, t0, s0\n"
	"min r3.w, r0, r3.y\n"
	"max r3.y, r3.x, r0.w\n"
	"cmp r1, -r3.z, r1, r2\n"
	"add r3.y, r3, -r3.w\n"
	"mad r2.x, r3.y, c4, -r3\n"
	"cmp r0, r2.x, r1, r0\n"
	"mov oC0, r0\n";
