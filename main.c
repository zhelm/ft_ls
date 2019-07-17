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
#include <grp.h>
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
	struct dirent *de;
	struct stat sb;
	char outstr[200];
	DIR *dr;

	dr = opendir(".");
	while((de = readdir(dr)) != NULL)
	{
		stat(de->d_name, &sb);
		printf("		name of file =		%s\n", de->d_name);
		printf(" file position within stream = 		%d\n", de->d_reclen);
		printf("		   File Type = 		%d\n", de->d_type);
		printf("		   stat mode = 		%o\n", sb.st_mode);//prints mode in octal
		printf("		   stat size =		%ld\n", sb.st_size);//prints size of file
		struct passwd *pw = getpwuid(sb.st_uid);//this gets the name
		printf("		   user name =		%s\n", pw->pw_name);//
		struct group  *gr = getgrgid(sb.st_gid);//this gets the group name
		printf("		  group name =		%s\n", gr->gr_name);
		printf("   time of last modification =		%s\n\n", ctime(&sb.st_ctime));
	}
	
}
//file mode, links(are these hard links or soft links or both?), owner name, group name, number of bytes ,  month, day file was last modified, time file was last modified, and the pathname
//		||-rw-r--r--||   1//just figure out how to get this    ||zhelm||   ||student||     ||20430||           ||Jul||              ||17||                        ||12:08||                     ||Notes||
