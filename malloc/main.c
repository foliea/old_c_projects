int	main()
{
  char	*str;

  malloc(5);
  malloc(10);
  malloc(15);
  str = malloc(20);
  str = realloc(str, 50);
  return (0);
}
