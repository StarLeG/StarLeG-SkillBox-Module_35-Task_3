#include <iostream>
#include <filesystem>
#include <vector>
#include <string>
#include <algorithm>


namespace fs = std::filesystem;

int main()
{
	auto cur_p = fs::current_path();
	std::cout << cur_p << std::endl;

	auto root_p = fs::path("C:");
	auto space = fs::space(root_p);

	std::cout << "Total : " << space.capacity / 1024 / 1024 / 1024 << " GB" << std::endl;
	std::cout << "Free : " << space.free / 1024 / 1024 / 1024 << " GB" << std::endl;
	std::cout << "Available : " << space.available / 1024 / 1024 / 1024 << " GB" << std::endl;

	fs::path apath("c:\\Users\\briti\\Documents\\Partnership.pdf");
	std::cout << "Path to file: " << apath << std::endl;
	std::cout << "File name: " << apath.filename() << std::endl;
	std::cout << "Extension: " << apath.extension() << std::endl;

	if (apath.extension().compare("pdf"))
	{
		std::cout << "This file is a pdf file." << std::endl;
	}
	else
	{
		std::cout << "This file is not a pdf file." << std::endl;
	}


	auto recursiveGetFileNamesByExtension =
			[](fs::path& path,
					const std::vector<std::string>& extension)
			{
				std::vector<std::string> file;
				for (auto& p: fs::recursive_directory_iterator(path))
				{
					if (fs::is_regular_file(p))
					{
						if (extension.empty()
							|| std::find(extension.begin(), extension.end(), p.path().extension().string()) !=
							   extension.end())
						{
							file.push_back(p.path().string());
						}
					}
				}
				return file;
			};
	apath = fs::current_path();
	auto file = recursiveGetFileNamesByExtension(apath, {  });

	for(auto i : file)
	{
		std::cout << i << std::endl;
	}

	file = recursiveGetFileNamesByExtension(apath, { ".txt" });

	std:: cout << "*****************************************************\n";
	for(auto i : file)
	{
		std::cout << i << std::endl;
	}

	return 0;
}
