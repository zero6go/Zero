#pragma once

#include "Zero/Core/Buffer.h"

namespace Zero {

	class FileSystem
	{
	public:
		// TODO: move to FileSystem class
		static Buffer ReadFileBinary(const std::filesystem::path& filepath);
	};

}