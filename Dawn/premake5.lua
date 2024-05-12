workspace "Dawn"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Dawn"
	location "Dawn"
	kind "SharedLib"
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
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22000.0"

		defines
		{
			"DAWN_PLATFORM_WINDOWS",
			"DAWN_BUILD_DLL",
		}

		postbuildcommands
		{
			("{COPY} %(cfg.buildtarget.relpath) ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "DAWN_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "DAWN_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DAWN_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
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
		"Dawn/vendor/spdlog/include",
		"Dawn/src"
	}

	links
	{
		"Dawn"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22000.0"

		defines
		{
			"DAWN_PLATFORM_WINDOWS",
		} 

		filter "configurations:Debug"
			defines "DAWN_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "DAWN_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "DAWN_DIST"
			optimize "On"
