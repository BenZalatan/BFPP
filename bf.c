#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* MEMORY */
#define MEMORY_SIZE 255
unsigned char memory[MEMORY_SIZE];
unsigned char ptr;
short ref = -1, temp;

/* TERMINAL */
char input[80];
unsigned char i;
unsigned char debug;

/* LOOPS */
unsigned char ifCount, whileCount;

int main()
{
	while (1)
	{
		printf("::: ");
		scanf("%s", input);

		i = 0;

		if (!strcmp(input, "quit"))
			return 0;
		else if (!strcmp(input, "clear"))
		{
			system("cls");
			continue;
		}
		else if (!strcmp(input, "dump"))
		{
			for (temp = 0; temp < MEMORY_SIZE; temp++)
				printf("%u = %u\n", temp, memory[temp]);
			continue;
		}
		else if (!strcmp(input, "debug"))
		{
			debug = !debug;
			if (debug) printf("Debug mode on.\n");
			else printf("Debug mode off.\n");
			continue;
		}
		else if (!strcmp(input, "reset"))
		{
			for (i = 0; i < MEMORY_SIZE; i++)
				memory[i] = 0;
			ptr = 0;
			ref = -1;
			temp = 0;
			printf("Memory reset.\n");
			continue;
		}
		else if (!strcmp(input, "info"))
		{
			printf("Pointer: %u\n", ptr);
			printf("Value:   %u\n", memory[ptr]);
			if (ref >= 0)
			{
				printf("Ref:     %u\n", ref);
				printf("Ref Val: %u\n", memory[ref]);
			}
			else
				printf("No reference set.\n");
			continue;
		}

		while (input[i])
		{
			if (debug) printf("%u BEGIN: c='%c', p=%u @ %u, r=%u @ %i\n", i, input[i], memory[ptr], ptr, ref >= 0 ? memory[ref] : 0, ref);
			switch (input[i])
			{
			/* Move right */
			case '>':
				ptr++;
				break;
			/* Move left */
			case '<':
				ptr--;
				break;
			/* Increment/add */
			case '+':
				memory[ptr] += ref >= 0 ? memory[ref] : 1;
				break;
			/* Decrement/subtract */
			case '-':
				memory[ptr] -= ref >= 0 ? memory[ref] : 1;
				break;
			/* Double/multiply */
			case '*':
				memory[ptr] *= ref >= 0 ? memory[ref] : 2;
				break;
			/* Half/divide */
			case '/':
				memory[ptr] /= ref >= 0 ? memory[ref] : 2;
				break;
			/* Set equal to */
			case '=':
				if (ref >= 0) memory[ptr] = memory[ref];
				break;
			/* Invert */
			case '!':
				memory[ptr] = !memory[ptr];
				break;
			/* Print */
			case '.':
				printf("%u", memory[ptr]);
				break;
			/* Print a space character */
			case '_':
				printf(" ");
				break;
			/* Get input */
			case ',':
				printf("Input: ");
				scanf("%u", &memory[ptr]);
				break;
			/* Set reference pointer */
			case '@':
				ref = ptr;
				break;
			/* Break reference */
			case 'x':
				ref = -1;
				break;
			/* Swap reference and current pointer */
			case 's':
				if (ref >= 0)
				{
					temp = ref;
					ref = ptr;
					ptr = temp;
				}
				break;
			/* Stop execution */
			case 'q':
				input[i] = 0;
				i--;
				break;
			/* If */
			case '(':
				temp = 0;
				if (ref >= 0)
				{
					switch (input[i + 1])
					{
					case '=':
						temp = memory[ptr] == memory[ref];
						break;
					case '>':
						temp = memory[ptr] > memory[ref];
						break;
					case '<':
						temp = memory[ptr] < memory[ref];
						break;
					case '!':
						temp = memory[ptr] != memory[ref];
						break;
					default:
						printf("Invalid if operator '%c'", input[i + 1]);
						break;
					}
					i++;
				}
				else temp = memory[ptr] != 0;

				if (!temp)
				{
					temp = i;
					ifCount = 0;
					while (input[temp++])
					{
						if (input[temp] == ')')
						{
							if (!ifCount) i = temp;
							ifCount--;
						}
						else if (input[temp] == '(') ifCount++;
					}
				}

				break;

			/* While */
			case '{':
				temp = 0;
				if (ref >= 0)
				{
					switch (input[i + 1])
					{
					case '=':
						temp = memory[ptr] == memory[ref];
						break;
					case '>':
						temp = memory[ptr] > memory[ref];
						break;
					case '<':
						temp = memory[ptr] < memory[ref];
						break;
					case '!':
						temp = memory[ptr] != memory[ref];
						break;
					case '1':
						temp = 1;
						break;
					case '0':
						temp = memory[ptr] != 0;
						break;
					default:
						printf("Invalid if operator '%c'", input[i + 1]);
						break;
					}
					i++;
				}
				else temp = memory[ptr] != 0;

				if (!temp)
				{
					temp = i;
					whileCount = 0;
					while (input[temp++])
					{
						if (input[temp] == '}')
						{
							if (!whileCount) i = temp;
							whileCount--;
						}
						else if (input[temp] == '{') whileCount++;
					}
				}

				break;

			case '}':
				temp = i;
				whileCount = 0;
				while (input[temp--])
				{
					if (input[temp] == '}')
						whileCount++;
					else if (input[temp] == '{')
					{
						if (!whileCount) i = temp - 1;
						whileCount++;
					}
				}

				break;

			default:
				break;
			}

			if (debug) printf("%u END:   c='%c', p=%u @ %u, r=%u @ %i\n", i, input[i], memory[ptr], ptr, ref >= 0 ? memory[ref] : 0, ref);
			i++;
		}
		printf("%c", '\n');
	}
	return 0;
}