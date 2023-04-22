#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
		unsigned int i;
			char *p = (char *)format;
				va_list args;
					va_start(args, format);
						char* var;
							char chvar;
								
								while (*p)
										{
													if (*p == '%')
																{
																				switch (*(p+1))
																								{
																												case 'c':
																																	chvar = va_arg(args,int);
																																					write(1,&chvar,1);
																																									p++;
																																													break;
																																																case 's':
																																																	var = va_arg(args,char *);
																																																					write(1, var, sizeof(var));
																																																									p++;
																																																													break;
																																																																case '%':
																																																																	write(1,"%",1);
																																																																					p++;
																																																																								default:
																																																																									break;
																																																																												}
																						}
															else
																		write(1, p, 1);
																	p++;
																		}
									
									
}
