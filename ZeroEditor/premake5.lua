project "ZeroEditor"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

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
		"%{IncludeDir.filewatch}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}",
		"%{IncludeDir.ImGuizmo}"
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
