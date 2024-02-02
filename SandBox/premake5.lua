project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/Zero/vendor/spdlog/include",
		"%{wks.location}/Zero/src",
		"%{wks.location}/Zero/vendor",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}"
	}

	links
	{
		"Zero"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "ZERO_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "ZERO_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "ZERO_DIST"
		runtime "Release"
		optimize "on"
