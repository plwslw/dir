#include<stdio.h>
#include<string.h>
#include<dirent.h>
#include<string.h>
#include<sys/types.h>
#include<errno.h>

/*
You will write a program that will gather various information about a directory, specifically:

    list all the files in the directory
    specify which files are directories (if any)
    show the total size of all the regular files the directory
        note that you do not have to recursively go through any subdirectories to find their size for this part (unless you want to, but that is not a simple task)
    Have the program scan the current directory
    Possible enhancements:
        Recursively list the files in any subdirectories, update the total to include the total size of subdirectories
        Print out the size in a more readable format (like using KB, MB, GB for -byte prefixes)
*/

char* filesize(int bytes){}

DIR* ls(char* path){
  DIR *dir;
  struct dirent *entry;
  
  if ((dir = opendir(path)) == NULL)
    print("%s", strerror(errno));
    
//we first look only for directories
  while (entry=readdir(dir) != NULL){//while entry exists
    if (opendir(entry.d_name) )
	 
}

int main(){
    ls(".");
}
}
