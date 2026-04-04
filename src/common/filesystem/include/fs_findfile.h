#pragma once
// Directory searching routines

#include <stdint.h>
#include <vector>
#include <string>

#ifdef BUILD_TARGET_WXP32
int my_wstat64(const wchar_t *path, struct _stat64 *buffer);
#endif 

namespace FileSys {
	
struct FileListEntry
{
	std::string FileName;		// file name only
	std::string FilePath;		// full path to file
	std::string FilePathRel;	// path relative to the scanned directory.
	size_t Length = 0;
	bool isDirectory = false;
	bool isReadonly = false;
	bool isHidden = false;
	bool isSystem = false;
};

using FileList = std::vector<FileListEntry>;

struct FCompressedBuffer;
bool ScanDirectory(std::vector<FileListEntry>& list, const char* dirpath, const char* match, bool nosubdir = false, bool readhidden = false);
bool FS_DirEntryExists(const char* pathname, bool* isdir);

inline void FixPathSeparator(char* path)
{
	while (*path)
	{
		if (*path == '\\')
			*path = '/';
		path++;
	}
}

}
