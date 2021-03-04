#include "mini_paint.h"

int calcul_dist(int i, int j, t_circle c)
{
	c.dist = sqrtf((i - c.x) * (i - c.x) + (j - c.y) * (j - c.y));
    if (c.dist > c.r)
        return (0);
    if (c.r - c.dist < 1)
        return (1);
    if (c.c == 'C')
        return (1);
	return (0);
}

int draw_circle(FILE *fd)
{
    int r, i, j;
    char buff[90000];
    t_circle c;

    r = fscanf(fd, "%d %d %c\n", &c.w, &c.h, &c.b);
    if (r == 3)
    {
        if (c.w <= 0 || c.w > 300 || c.h <= 0 || c.h > 300)
            return (1);
	    memset(buff, c.b, c.w * c.h);
        while ((r = fscanf(fd, "%c %f %f %f %c\n", &c.c, &c.x, &c.y, &c.r, &c.d)) == 5)
        {
            if ((c.c != 'c' && c.c != 'C') || c.r <= 0)
                return (1);
            for (i = 0; i < c.h; i++)
            {
                for(j = 0; j < c.w; j++)
                {
                    if (calcul_dist(j, i, c))
                        buff[i * c.w + j] = c.d;
                }
            }
        }
        if (r != EOF)
            return (1);
        for (i = 0; i < c.h; i++)
        {
            write(1, buff + (c.w * i), c.w);
            write(1, "\n", 1);
        } 
        return (0);
    }
    return (1);
}

int main(int argc, char **argv)
{
	FILE *fd;
    
    if (argc == 2)
    {
        fd = fopen(argv[1], "r");
        if (fd && !draw_circle(fd))
        {
            fclose(fd);
            return (0);
        }
        write(2, "Error : Operation file corrupted \n", 34);
        fclose(fd);
    }
    else
        write(1, "Error: argument\n", 16);
	return (1);
}
