include "./vendor/premake/premake_customization/solution_items.lua"

workspace "Zero"
	architecture "x86_64"
	startproject "Zeronut"

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

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/Zero/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/Zero/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/Zero/vendor/imgui"
IncludeDir["glm"] = "%{wks.location}/Zero/vendor/glm"
IncludeDir["stb_image"] = "%{wks.location}/Zero/vendor/stb_image"
IncludeDir["entt"] = "%{wks.location}/Zero/vendor/entt/include"

group "Dependencies"
	include "vendor/premake"
	include "Zero/vendor/GLFW"
	include "Zero/vendor/Glad"
	include "Zero/vendor/imgui"
group ""

include "Zero"
include "Sandbox"
include "Zeronut"