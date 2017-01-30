/* Marcus Botacin
 * Sample for study purposes
 * Virus-Like Behavior
 * Enumerates *.lnk files on a given directory
 */


/* Basic Includes */
#include<stdio.h>
#include<Windows.h>

/* Search Path */
const char* SEARCH_PATTERN="C:\\Teste\\*.lnk";

/* What would be the infection routine */
void infect(HANDLE hFind)
{
	printf("infected\n");
}

/* Main */
int main()
{
	WIN32_FIND_DATAA FindFileData;
	HANDLE hFind;
	
	/* Find first file on a directory */
	hFind = FindFirstFileA(SEARCH_PATTERN, &FindFileData);
	/* if found, infect */
	if(hFind!=INVALID_HANDLE_VALUE)
	{
		  printf("%s\n", FindFileData.cFileName);
		  infect(hFind);
	/* if not found, get out! */
	}else{
		return 0;
	}

	/* list traversal
	 * keep infecting
	 */
	while(FindNextFileA(hFind,&FindFileData)!=0)
	{
	  printf("%s\n", FindFileData.cFileName);
	  infect(hFind);
	}

	return 0;
}
