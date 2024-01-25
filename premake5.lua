workspace "Zero"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Zero/vendor/GLFW/include"
IncludeDir["Glad"] = "Zero/vendor/Glad/include"
IncludeDir["ImGui"] = "Zero/vendor/imgui"
IncludeDir["glm"] = "Zero/vendor/glm"

include "Zero/vendor/GLFW"
include "Zero/vendor/Glad"
include "Zero/vendor/imgui"

project "Zero"
	location "Zero"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "zpch.h"
	pchsource "Zero/src/zpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"ZERO_PLATFORM_WINDOWS",
			"ZERO_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "ZERO_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "ZERO_RELEASE"
		runtime "Release"
		symbols "On"

	filter "configurations:Dist"
		defines "ZERO_DIST"
		runtime "Release"
		symbols "On"

project "SandBox"
	location "SandBox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Zero/vendor/spdlog/include",
		"Zero/src",
		"Zero/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Zero"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"ZERO_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "ZERO_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "ZERO_RELEASE"
		runtime "Release"
		symbols "On"

	filter "configurations:Dist"
		defines "ZERO_DIST"
		runtime "Release"
		symbols "On"