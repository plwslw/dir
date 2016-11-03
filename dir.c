#include<stdio.h>
#include<string.h>
#include<dirent.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
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

void print_filesize(unsigned long bytes){
  printf("size = ");
  if (bytes<1024){
    printf("%lu Bytes \n", bytes); 
    return;
  }
  bytes/=1024;
  if (bytes<1024){
    printf("%lu KB \n", bytes);
    return;
  }
  bytes/=1024;
  if (bytes<1024){
    printf("%lu MB \n", bytes);
    return;
  }
  bytes/=1024;
  printf("%lu GB \n", bytes);
  return;
    
}

//Prints out a list of the contents of the directory
//Assumes the directory contains only files and directories.
//returns the size of the directory or -1 if there is an error
unsigned long ls(char* path){
  printf("Stats for directory %s\n", path);
  
  DIR *dir;
  struct dirent *entry;
  if ((dir = opendir(path)) == NULL){
    printf("%s \n", strerror(errno));
    printf("terminating ls \n");
    return -1;
  }


  printf("Directories \n");
  DIR *tmp;
  //we first look only for directories
  while ((entry=readdir(dir)) != NULL){//while entry exists
    tmp = opendir(entry->d_name);
    if (tmp!=NULL) //only true if entry is a directory
      printf("\t %s \n", entry->d_name);
  }

  
  struct stat stats;
  unsigned long size=0; //# bytes

  dir=opendir(path); //restarts dir
  printf("Regular files \n");
  //now we look only for regular files
  while ((entry=readdir(dir)) != NULL){
    tmp = opendir(entry->d_name);
    if (tmp==NULL){ //true if entry is not a directory.
      printf("\t %s \n", entry->d_name);
      stat(entry->d_name, &stats);
      size+=(unsigned long)stats.st_size;
    }
  }

  print_filesize(size);
  //printf("%lu", size);
  return size;   
  
}

int main(){
    ls(".");
    return 0;
}
