workspace "Zero"
	architecture "x64"

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

include "Zero/vendor/GLFW"

project "Zero"
	location "Zero"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "zpch.h"
	pchsource "Zero/src/zpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links 
	{ 
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ZERO_PLATFORM_WINDOWS",
			"ZERO_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "ZERO_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ZERO_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "ZERO_DIST"
		symbols "On"

project "SandBox"
	location "SandBox"
	kind "ConsoleApp"
	language "C++"

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
		"Zero/src"
	}

	links
	{
		"Zero"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ZERO_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "ZERO_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ZERO_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "ZERO_DIST"
		symbols "On"