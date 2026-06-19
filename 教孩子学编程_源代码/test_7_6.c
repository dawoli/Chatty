#include <stdio.h>
#include <stdlib.h>
int main()
{
	int cock,hen,chicken;
    for(cock=0;cock<=20;cock++)
		for(hen=0;hen<=(100-cock*5)/3;hen++)
        {
			chicken = (100-cock*5-hen*3)*3;
            if(cock+hen+chicken == 100)
				printf("cock=%2d hen=%2d chicken=%2d\n",cock,hen,chicken);
        }
    printf("\n");        
	system("pause");
	return 0;
}
