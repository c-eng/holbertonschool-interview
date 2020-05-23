#include <stdlib.h>
#include <string.h>

/**
 * find_substring - finds substrings
 * @s: string to scan
 * @words: array of substring fragments
 * @nb_words: number of substring fragments
 * @n: store number of substrings here
 * Return: array containing indexes
 */

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	char *temp = NULL, *p = NULL;
	int slen, dictlen = 0, count = 0, regwordlen, i, j, k;
	int *pmark = NULL;

	slen = strlen(s);
	regwordlen = strlen(words[0]);
	dictlen = regwordlen * nb_words;
	temp = calloc((dictlen + 1), sizeof(char));
	pmark = calloc((slen + 1), sizeof(char));
	for (i = 0; i <= slen - dictlen;)
	{
		strncpy(temp, &s[i], dictlen);
		for (j = 0; j < nb_words; j++)
		{
			for (k = 0; k < dictlen;)
			{
				p = strstr(temp + k, words[j]);
				if (p != NULL && ((p - temp) % regwordlen) == 0)
					break;
				else if (p != NULL)
				{
					k = p - temp + 1;
					p = NULL;
				}
				else if (p == NULL)
					goto nextseg;
			}
			if (p != NULL)
				memset(p, '.', regwordlen);
			else
				goto nextseg;
		}
		if (slen != 0 && dictlen != 0)
			pmark[count++] = i;
nextseg:
		i++;
	}
	free(temp);
	*n = count;
	return (pmark);
}
