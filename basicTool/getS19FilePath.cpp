#include <dirent.h>
#include <iostream>
#include <regex>
#include <string>
using namespace std;
//std::vector<std::string> get_all_files(std::string path, std::string suffix)
string get_all_files(std::string path, std::string suffix)
{
    //std::vector<std::string> files;
    std::string files;
    files.clear();
    DIR *dp;
    struct dirent *dirp;
    if((dp = opendir(path.c_str())) == NULL)
    {
        cout << "Can not open " << path << endl;
        return files;
    }
    //regex reg_obj(suffix, regex::icase);
    while((dirp = readdir(dp)) != NULL)
    {
    	if ((dirp->d_type == DT_REG) && 0 ==(strcmp(strchr(dirp->d_name, '.'), suffix.c_str())))//判断是否为文件以及文件后缀名
		{
			files = path + dirp->d_name;
			break;
		}
//         if(dirp -> d_type == 8)  // 4 means catalog; 8 means file; 0 means unknown
//         {
//             if(regex_match(dirp->d_name, reg_obj))
//             {
// //                cout << dirp->d_name << endl;
//                 string all_path = path + dirp->d_name;
//                 //files.push_back(all_path);
//                 files = all_path;
//                 cout << dirp->d_name << " " << dirp->d_ino << " " << dirp->d_off << " " << dirp->d_reclen << " " << dirp->d_type << endl;
//             }
//         }
    }
    closedir(dp);
    return files;
}


int main()
{
	printf("hello world\n");
	
	std::string path= "/home/tbox/Downloads/mpu/";
	std::string name= ".txt";

	string test = get_all_files(path,name);
	if(test == "")
		printf("string = %s\n",test.c_str());


	return 0;
}
