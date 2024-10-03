#include "get_next_line.h"

int main(int argc, char **argv)
{
	int fd;
	char *line;

	// Comprobar que se pasó el nombre del archivo como argumento
	if (argc != 2)
	{
		fprintf(stderr, "Uso: %s <nombre_de_archivo>\n", argv[0]);
		return (1);
	}

	// Abrir el archivo
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error al abrir el archivo");
		return (1);
	}

	// Leer líneas hasta que no haya más
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line); // Imprimir la línea leída
		free(line);         // Liberar la memoria asignada para la línea
	}

	// Cerrar el archivo
	close(fd);
	return (0);
}