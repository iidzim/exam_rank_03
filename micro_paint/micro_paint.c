#include "micro_paint.h"

int rect(int i, int j, t_rectangle r)
{
    if (i < r.x || i > r.x + r.r_width || j < r.y || j > r.y + r.r_height)
        return (0);
    if (i - r.x < 1.00000 || (r.x + r.r_width) - i < 1.00000 || j - r.y < 1.00000 || (r.y + r.r_height) - j < 1.00000)
        return (1);
    if (r.c == 'R')
        return (1);
    return (0);
}

int draw_rect(FILE *fd)
{
	int ret, i, j;
    char buff[90000];
	t_rectangle rec;
	
    ret = fscanf(fd, "%d %d %c\n", &rec.w, &rec.h, &rec.b);
    if (ret == 3)
    {
        if (rec.w <= 0 || rec.w > 300 || rec.h <= 0 || rec.h > 300)
            return (1);
	    memset(buff, rec.b, rec.w * rec.h);
        while ((ret = fscanf(fd, "%c %f %f %f %f %c\n", &rec.c, &rec.x, &rec.y, &rec.r_width, &rec.r_height, &rec.d)) == 6)
        {
            if ((rec.c != 'r' && rec.c != 'R') || rec.r_width <= 0 || rec.r_height <= 0)
                return (1);
            for (i = 0; i < rec.h;  i++)
            {
                for(j = 0; j < rec.w; j++)
                {
					if (rect(j, i, rec))
                        buff[i * rec.w + j] = rec.d;
				}
			}
		}
		if (ret == EOF)
        {
           for (i = 0; i < rec.h; i++)
            {
                write(1, buff + rec.w * i, rec.w);
                write(1, "\n", 1);
            } 
            return (0);
        }
	}
    return (1);
}

int main(int argc, char **argv)
{
	FILE *fd;
	
	if (argc == 2)
	{
		fd = fopen(argv[1], "r");
        if (fd && !draw_rect(fd))
        {
            fclose(fd);
            return (0);
        }
        write(2, "Error: Operation file corrupted\n", 32);
        fclose(fd);
	}
    else
        write(1, "Error: argument\n", 16);
	return (1);
}