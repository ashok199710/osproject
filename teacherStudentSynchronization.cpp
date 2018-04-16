#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/types.h>
#include<fcntl.h>

char unlimitedResource[3] = {'P', 'p', 'Q'};
struct studentResource
{
	int pen;
	int paper;
	int Qpaper;
}s[3];
pthread_mutex_t lock;
void *stud1();
void *stud2();
void *stud3();
int main()
{
	s[0].pen=1;
	s[1].paper=1;
	s[2].Qpaper=1;
	pthread_t student1;
	pthread_t student2;
	pthread_t student3;
	pthread_mutex_init(&lock, NULL);
	printf("\nTeacher- Student Assignment Problem:");
	printf("\nTeacher-generated resources are:");
//	printf("\nThe generated resources are: %c, %c", unlimitedResource[rand()%3], unlimitedResource[rand()%3]);
	int i=1;
	while(i)
	{
		int temp1 = rand()%3;
		int temp2 = rand()%3;
		if(temp1 == temp2) continue;
		else
		{
			printf("\nThe teacher generated resources are %c and %c", unlimitedResource[temp1], unlimitedResource[temp2]);
			if((temp1 == 0 && temp2 ==1) || (temp1 == 1 && temp2 ==0))
			{
				pthread_create(&student3, NULL, stud3, NULL);
				pthread_join(student3, NULL);
			}
			else if((temp1 == 1 && temp2 ==2) || (temp1 == 2 && temp2 ==1))
			{
				pthread_create(&student1, NULL, stud1, NULL);
				pthread_join(student1, NULL);
			}
			else if((temp1 == 0 && temp2 == 2) || (temp1 ==2 && temp2 ==0))
			{
				pthread_create(&student2, NULL, stud2, NULL);
				pthread_join(student2, NULL);
			}
		}
		//i++;
	}
}

void *stud1()
{
	pthread_mutex_lock(&lock);
	printf("\nYes, student1 done with the assignment...!");
	pthread_mutex_unlock(&lock);
}

void *stud2()
{
	pthread_mutex_lock(&lock);
	printf("\nYes, student2 done with the assignment..!");
	pthread_mutex_unlock(&lock);
}

void *stud3()
{
	pthread_mutex_lock(&lock);
	printf("\nYes, student3 done with the assignment..!");
	pthread_mutex_unlock(&lock);
}


