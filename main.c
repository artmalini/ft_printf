#include "includes/libft.h"
#include "includes/ft_printf.h"
#include <locale.h>
int 		main(void)
{
	int i, j, k;
	i = 0;
	j = 0;
	k = 0;
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
	printf("My$$ %d\n", i);

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

	i =	ft_printf("%e\n", 	345.9265e-2);
	j = printf("%e\n", 	345.9265e-2);
	printf("Moi %d Base : %d\n", i, j);

	ft_printf("% d\n", 2147483648);

	
	//ft_printf("%s\n", (void*)42);
	float f1 = 100; float f2 = 0;

	printf("%10.2f\n", f1 / f2);
	ft_printf("%10.2f\n", f1 / f2);

	printf("%F\n", f1 / f2);
	ft_printf("%F\n", f1 / f2);


	printf("%10.2A\n", f1 / f2);
	ft_printf("%10.2A\n", f1 / f2);

	printf("%F\n", 100.345);
	ft_printf("%F\n", 100.345);

	f1 = 0; f2 = 0;
	ft_printf("nan %f\n", f1 / f2);

	ft_printf("|+0005.e-01|%0+#10.e\n", 0.5);
	ft_printf("|+5.e-01   |%0+-#10.e|\n", 0.5);
	ft_printf("| 0001.E+03|% 0#10.E|\n", 1024.05);

	ft_printf("|-9.99E+02|% +#8.2E|\n", -999.999);

	ft_printf("|    5.E-01|% #10.E|\n", 0.5);
	ft_printf("|+5e-01    |% 0+-10.e|\n", 0.5);
	ft_printf("|+00005e-01|% 0+10.e|\n", 0.5);

	ft_printf("|   -5.e-01|%#10.e|\n", -0.5);
	ft_printf("|-1.E+03   |%+-#10.E|\n", -1024.05);
	/*ft_printf("1|| |%.0hhu|\n", 1024);
	ft_printf("2| 1024|% .0d|\n", 1024);

	ft_printf("3| | |% .0hhd|\n", 1024);
	ft_printf("4|| |%#.0hhd|\n", 1024);

	ft_printf("5|0|%+#.0hho|\n", 1024);//0
	ft_printf("6|| |%+#.0hhu|\n", 1024);//empty

	printf("7|0 |%#.o, %#.0o|\n", 0, 0);//0
	ft_printf("7|0 |%#.o, %#.0o|\n", 0, 0);//0

	printf("8|, |%.o, %.0o|\n", 0, 0);//empty
	ft_printf("8|, |%.o, %.0o|\n", 0, 0);//empty

	printf("9|0 |%#o|\n", 0);//0
	ft_printf("9|0 |%#o|\n", 0);//0

	printf("11|0 |%#.O|\n", 0);//0
	ft_printf("11|0 |%#.O|\n", 0);//0

	printf("12|001|%#.3o|\n", 1);//001 del hex
	ft_printf("12|001|%#.3o|\n", 1);//001 del hex	

	ft_printf("14|0|%+#.0hho|\n", 1024);//0

	ft_printf("15|037777777747|%#*.*o|\n", 5, 4, -25);//hex
	ft_printf("16|037777777747|%#-5.3o|\n", -25);//hex
	ft_printf("17| 017777777777| %-#13.12O|\n", 2147483647);//del hex	
	ft_printf("18|037777777747|%#5.4o|\n", -25);//hex
	ft_printf("19|{00042}|{%.*d}\n", 5, 42);
	ft_printf("20|-0000000042 %.10d|\n", -42);

	ft_printf("21| 0347|%#5.4hho|\n", -25);//del hex

	ft_printf("22|037777777747|%#5.4lo|\n", -25);//hex
	ft_printf("23|037777777747|%-#5.4o|\n", -25);//hex
	ft_printf("24|0347 |%-#5.4hho|\n", -25);//del hex
	ft_printf("25|037777777747|%-#5.4jo|\n", -25);//hex
	ft_printf("26|0000|%#.4o|\n", 0);//del hex
	ft_printf("27|  031|%#5.3o|\n", 25);//del hex
	ft_printf("28|037777777747|%#5.3o|\n", -25);//hex
	ft_printf("29|  031|%#5.3ho|\n", 25);//hex
	ft_printf("30|031  |%-#5.3o|\n", 25);//del hex
	ft_printf("31|  031|%#5.1o|\n", 25);//hex
	ft_printf("32|  031|%#5.1hho|\n", 25);//hex
	ft_printf("33|0347 |% 0+#-5.3hho|\n", -25);//hex
	ft_printf("33|0347 |%-#-5.3hho|\n", -25);//hex


	printf("1|0|%#x|\n", 0);//0
	ft_printf("1|0|%#x|\n", 0);//0	
	ft_printf("2||%#.0hhx|\n", 1024);//empty del hex
	ft_printf("3|0000|%#.4hhx|\n", 0);//0000 del hex
	ft_printf("4|00000|%0#5hhx|\n", 0);//0000 del hex
	ft_printf("5|0x2a||%#x|\n", 42);
	ft_printf("6{0x00001} {%#.5x}\n", 1);//hex
	ft_printf("7|00000|%0#5hx|\n", 0);//0000 del hex
	ft_printf("8|0|%#x|\n", 0);//0 del hex	
	ft_printf("9||%#.0llx|\n", 0);//empty del hex
	ft_printf("10||%#.0hx|\n", 0);//empty del hex
	ft_printf("11|00000|%#.4hx|\n", 0);//0000 del hex
	ft_printf("|0|% +#zX|\n", 0);
	//ft_printf("1| |% .0d|\n", 0);
	//ft_printf("2|+|%+.0d|\n", 0);

	i = ft_printf("1||(nul||%.3s|\n", NULL);
	j = printf("1||(nul||%.3s|\n", NULL);
	printf("My %d Basic %d\n", i, j);
	i = ft_printf("2|(null)|%s|\n", NULL);
	j = printf("2|(null)|%s|\n", NULL);
	printf("My %d Basic %d\n", i, j);

//n
	ft_printf("|blackbird  |%n\n", &k);
	printf("My k %d\n", k);

	i = ft_printf("|%05.4hhx|%n\n", -25, &k);
	printf("My k %d i %d\n", k, i);*/


	/*ft_printf("1|(nu |%.3s |\n", NULL);
	ft_printf("2|blackb|%.6s|\n", "blackbird");
	ft_printf("|         c|%10.20s|\n", L"casual stringα");
	ft_printf("||%10.20ls|\n", L"casual stringα");*/


	//printf("1||%lc|\n", L'α');
	//ft_printf("1||%lc|\n", L'α');	

	//printf("L 017777777777 |%-#13.12O|\n", 2147483647);
	//printf("S 017777777777 |%-#13.12o|\n", 2147483647);
	//printf("ff 037777777747 |%#5.4o|\n", -25);
	//ft_printf("ff 037777777747 |%#-5.3o|\n", -25);

	//ft_printf("1'024 |%'.0d|\n", 1024);//1'024

	//system("leaks b");
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

	//printf("|%10.f|\n", 1024.1);
	//ft_printf("|%10.f|\n", 1024.1);

	return (0);
}