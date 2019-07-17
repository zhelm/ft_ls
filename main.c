/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 08:52:22 by zhelm             #+#    #+#             */
/*   Updated: 2019/07/15 10:56:10 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 
#include <dirent.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <uuid/uuid.h> 
#include <time.h>
#include <string.h>

// int main(void)//main to show opendir and readdir
// { 
//     struct dirent *de;  // Pointer for directory entry 
  
//     // opendir() returns a pointer of DIR type. '.' == Current directory;
//     DIR *dr = opendir(".."); 
  
//     if (dr == NULL)  // opendir returns NULL if couldn't open directory 
//     { 
//         printf("Could not open current directory" ); 
//         return 0; 
//     }
//     while ((de = readdir(dr)) != NULL) 
//     {
//             printf("%llu = ", de->d_namlen);
//             printf("%s\n", de->d_name);
//     }
//     closedir(dr);     
//     return 0; 
// }

int main()//main to test the ctime and mtime
{
    struct stat buf;//ctime is the last time the inode changed and mtime is the last time the file was modified.
    char mtime[100];



  // struct passwd *p;
// uid_t uid=0;

//  if ((p = getpwuid(uid)) == NULL)
//     perror("getpwuid() error");
//  else {
//     printf("getpwuid returned the following name and directory for user ID %d:n", (int) uid);
//     printf("pw_name : %sn", p->pw_name);
//     printf("pw_dir  : %sn", p->pw_dir);
//     }
    struct stat sb;
    char outstr[200];

    stat(".", &sb);

    struct passwd *pw = getpwuid(sb.st_uid);//this gets the name
    printf("%s\n", pw->pw_name);//
    
    struct group  *gr = getgrgid(sb.st_gid);
    printf("%d\n", gr->gr_name);
    

    //  lstat(".", &buf);
    // printf("st_mode 16877 is octal 40755, which denotes a directory (octal 40000) with permissions 755 (user has full rights, everyone else has read and traversal rights) = %o\n",buf.st_mode);
    // strcpy(mtime,ctime(&buf.st_ctime));
    // printf("st_mtime = %o\n", buf.st_uid);
}

//file mode, links, owner name, group name, number of bytes ,  month, day file was last modified, time file was last modified, and the pathname
//-rw-r--r--   1      zhelm       student      20430           Jul              17                        12:08                     Notes


// int getChmod(const char *path){
//     struct stat ret;

//     if (lstat(path, &ret) == -1) {
//         return -1;
//     }

//     return (ret.st_mode & S_IRUSR)|(ret.st_mode & S_IWUSR)|(ret.st_mode & S_IXUSR)|/*owner*/
//         (ret.st_mode & S_IRGRP)|(ret.st_mode & S_IWGRP)|(ret.st_mode & S_IXGRP)|/*group*/
//         (ret.st_mode & S_IROTH)|(ret.st_mode & S_IWOTH)|(ret.st_mode & S_IXOTH);/*other*/
// }

// int main(){

//     printf("%dX\n",getChmod("/etc/passwd"));

//     return 0;
// }