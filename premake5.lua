include "./vendor/premake/premake_customization/solution_items.lua"
include "Dependencies.lua"

workspace "Zero"
	architecture "x86_64"
	startproject "ZeroEditor"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	include "vendor/premake"
	include "Zero/vendor/Box2D"
	include "Zero/vendor/GLFW"
	include "Zero/vendor/Glad"
	include "Zero/vendor/msdf-atlas-gen"
	include "Zero/vendor/imgui"
	include "Zero/vendor/yaml-cpp"
group ""

group "Core"
	include "Zero"
	include "ZeroScriptCore"
group ""

group "Tools"
	include "ZeroEditor"
group ""
