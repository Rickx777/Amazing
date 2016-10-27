#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int rando(){
  int hey;
  int fd = open("/dev/random",O_RDONLY);
  if (fd == -1){
    printf("%s",strerror(errno));
    return;
  }
  read(fd,&hey,4);
  close(fd);
  return hey;
}


int main(){
  int list[10];
  int c;
  printf("Generating Randos Mis Amigos:\n");
  for(c = 0; c < 10; c++){
    list[c] = rando();
    printf("Random %d: %d\n",c,list[c]);
  }

  
  printf("\nCreating File and Writing Data in File. . .\n");
  int fd = open("./Nums.txt", O_CREAT,0644);
  close(fd);
  fd = open("./Nums.txt",O_WRONLY);
  write(fd,&list,40);
  close(fd);

  printf("\nReading Data from File. . .\n\n");
  int list2[10];
  fd = open("./Nums.txt", O_RDONLY);
  read(fd,&list2,40);
  close(fd);
  
  printf("Verification of the Same Randos Amigos\n");
  for(c = 0; c < 10; c++){
    printf("Random %d: %d\n",c,list2[c]);
  }
  
  return 0;
}
