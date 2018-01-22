#include "includes/libft.h"
#include "includes/ft_printf.h"

int 		main(void)
{
	int i, j;
	i = 0;
	j = 0;
		ft_printf("rx %#llx\n", 9223372036854775807);
	//printf("x %#llx", 9223372036854775807);

	i =	ft_printf("%#8x\n", 42);
	j = printf("%#8x\n", 42);
	printf("My %d Basic %d\n", i, j);

	i =	ft_printf("%5%\n");
	//j = printf("%5%\n");
	printf("My %d Basic %d\n", i, j);

	i =	ft_printf("%   %", "test");
	//j = printf("%   %", "test");
	printf("My %d Basic %d\n", i, j);

	i =	ft_printf("%#x\n", 0);
	j = printf("%#x\n", 0);
	printf("My %d Basic %d\n", i, j);


	i =	ft_printf("AAAAA@moulitest: %#.x %#.0x\n", 0, 0);
	j = printf("@moulitest: %#.x %#.0x\n", 0, 0);
	printf("My %d Basic %d\n", i, j);


	i =	ft_printf("%x\n", 4294967296);
	//j = printf("%x", 4294967296);

	i =	ft_printf("NBR@moulitest: %.d %.0d", 42, 43);
	//j = printf("@moulitest: %.d %.0d", 42, 43);
	printf("My %d Basic %d\n", i, j);
	printf("My %d Basic %d\n", i, j);


	printf("\nARG\n");
	ft_printf("%");

	printf("\n");
	printf("\nARG\n");
	ft_printf("%%");

	printf("\n\n");
	ft_printf("%lx\n", 4294967296);
	   printf("%lx\n", 4294967296);

	ft_printf("%#llx\n", 9223372036854775807);
	printf("\n");
	   printf("%#lx\n", 9223372036854775807);

	//i =  ft_printf("{%f}{%F}\n", 1.42, 1.42);
	//j =  printf("{%f}{%F}\n", 1.42, 1.42);
	// printf("My %d Basic %d\n", i, j);

	i =  ft_printf("{%f}\n", 1.42);
	j =  printf("{%f}\n", 1.42);
	 printf("My %d Basic %d\n", i, j);

	 i = ft_printf("A@moulitest: %.d %.0d\n", 0, 0);
	 j = printf("A@moulitest: %.d %.0d\n", 0, 0);
	 printf("My %d Basic %d\n", i, j);

	 i = ft_printf("{%*c}\n", -15, 0);
	 j = printf("{%*c}\n", -15, 0);
	 printf("My %d Basic %d\n", i, j);


	i = ft_printf("% ");
	printf("My %d\n", i);

	ft_printf("%ll#x\n", 9223372036854775807);

	ft_printf("%zhd\n", 4294967296);


	i = ft_printf("%hhd\n", 128);
	printf("My %d\n", i);

	ft_printf("%zhd\n", 4294967296);

	i = ft_printf("@main_ftprintf: %###-#0000 33...12..#0+0d", 256);
	printf("My %d\n", i);


		i = ft_printf("% +-#5.4hd\n", -25);
	printf("My %d\n", i);

			i = ft_printf("% +-#5.4tu\n", -25);
	printf("My %d\n", i);

		i =	ft_printf("%e\n", 	-0.9265e-2);
	j = printf("%e\n", 	-0.9265e-2);
	printf("Moi %d Base : %d\n", i, j);

//(printf_, "|%3 %02 %1$d|", 1024, 0.999643287658734658368543L, 42);
	ft_printf("% 0+-#5.4hhu", 	25);
	ft_printf("%zhd\n", 4294967296);

	int z;
	ft_printf("some text %n\n", &z);
	printf("z %d\n", z);

	//ft_printf("%f\n", 1444565.4576242);

	ft_printf("%.20f\n", -14445654446466463464367436437634734774574574574587458450901241252352372355424242.2456756769769792);
	printf("%.20f\n", -14445654446466463464367436437634734774574574574587458450901241252352372355424242.2456756769769792);


	//ft_printf("%.20f\n", -346340.14445654446466463464367436437634734774574574574587458450901241252352372355424242);
	//printf("%.20f\n", -346340.14445654446466463464367436437634734774574574574587458450901241252352372355424242);
	//ft_printf("%.20f\n", 34.457457);
	//printf("%.20f\n", 34.457457);


	ft_printf("{%05.s}\n", 0);

		ft_printf("%La\n", 9.0456L);
	printf("%La\n", 9.0456L);

			ft_printf("%e\n", 9.00);
	printf("%e\n", 9.00);

	ft_printf("dd %d\n", 0);

	ft_printf("dd % ##-**-+-#**-++#5.4hho\n", 456);

	ft_printf("%05.4ju\n", 543657345734578887);


	//3.000000	
	ft_printf("%La\n", 3.0L);
	printf("%La\n", 3.0L);

	i = ft_printf("%a\n", 3.0);
	j = printf("%a\n", 3.0);
	printf("Moi %d Base : %d\n", i, j);

	ft_printf("%.2a\n", 3.0457457);
	printf("%.2a\n", 3.0457457);

	//printf(" nbr %d\n", ft_printf("%#x", 42));

	//ft_printf("@moulitest: %s\n", NULL);

	//i = ft_printf("%4.15s\n", "42 is the answer");
	//j = printf("%4.15s\n", "42 is the answer");
	//printf("Moi %d Base : %d\n", i, j);
	//ft_printf("%b\n", 1);
	//ft_printf("%b\n", 2);
	//ft_printf("%b\n", 3);
	//ft_printf("%b\n", 4);
	//ft_printf("%b\n", 5);
	//ft_printf("%b\n", 6);
	//ft_printf("%b\n", 7);
	//ft_printf("%b\n", 8);
	//ft_printf("%b\n", 9);
	//ft_printf("%#b\n", 128);

	return (0);
}