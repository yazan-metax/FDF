/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:00:51 by yazan             #+#    #+#             */
/*   Updated: 2023/08/16 20:31:20 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static int	ft_word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s)
	{
		if (*s && *s != c)
			len++;
		s++;
	}
	return (len);
}

static char	**ft_mallo(const char *s, char c)
{
	char	**word;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	word = (char **)malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!word)
		return (NULL);
	while (i < ft_word_count(s, c))
	{
		while (s[j] == c)
			j++;
		k = 0;
		word[i] = (char *)malloc(sizeof(char) * (ft_word_len(&s[j], c)) + 1);
		if (!word[i])
			return (NULL);
		while (s[j] && s[j] != c)
			word[i][k++] = s[j++];
		word[i][k] = '\0';
		i++;
	}
	word[i] = NULL;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**words;

	if (!s)
		return (NULL);
	words = ft_mallo(s, c);
	if (!words)
		return (NULL);
	return (words);
}

/* int main(void)
{
    char *sentence = "  This is a test sentence.";
    char **words;
    int i;

    words = ft_split(sentence, ' ');
    for (i = 0; words[i] != NULL; i++)
        printf("%s\n", words[i]);
		printf("num of words:%d\n",ft_word_count(sentence, ' '));
		printf("here is the len of words: %d\n",ft_word_len(sentence, ' '));
    return (0);
} */