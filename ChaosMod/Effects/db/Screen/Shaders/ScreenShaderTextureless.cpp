#include <stdafx.h>

#include "Effects/Register/RegisterEffect.h"
#include "Memory/Hooks/ShaderHook.h"
#include "Memory/Snow.h"

CHAOS_VAR const char *ms_ShaderSrc = R"SRC(
float4 main(float4 v0 : SV_Position0, float4 v1 : TEXCOORD0, float4 v2 : TEXCOORD1) : SV_Target0
{
    return float4(1., 1., 1., 1.);
}
)SRC";

static void OnStart()
{
	Hooks::OverrideShader(OverrideShaderType::Snow, ms_ShaderSrc);
}

static void OnStop()
{
	Memory::SetSnow(false);
	Hooks::ResetShader();
}

static void OnTick()
{
	Memory::SetSnow(true);
}

// clang-format off
REGISTER_EFFECT(OnStart, OnStop, OnTick, 
	{
		.Name = "Textureless",
		.Id = "screen_textureless",
		.IsTimed = true,
		.EffectCategory = EffectCategory::Shader,
		.EffectGroupType = EffectGroupType::Shader
	}
);