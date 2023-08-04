/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:13:38 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/05 00:21:15 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define BOOLEAN int
# define TRUE 1
# define FALSE 0
# define SORT_SIZE 4

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_node
{
	int				num;
	size_t			index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	size_t	size;
	t_node	*head_a;
	t_node	*head_b;
}					t_stack;

t_node	*node_new(int num);
void	node_add_front(t_node *head, t_node *new);
void	node_add_back(t_node *head, t_node *new);
void	coordinate_compress(t_node *head_a);
t_stack	*node_list_init(size_t argc, char **argv, size_t start);

t_node	*head_init(void);
t_stack	*stack_init(void);
void	head_print(t_node *head, char *head_name);
void	stack_print(t_stack *stack);
size_t	get_stack_size(t_node *head);

void	head_free_all(t_node *head);
void	stack_free_all(t_stack *stack);

void	ss(t_node *head_a, t_node *head_b);
void	sa(t_node *head_a);
void	sb(t_node *head_b);
void	rr(t_node *head_a, t_node *head_b);
void	ra(t_node *head_a);
void	rb(t_node *head_b);
void	rrr(t_node *head_a, t_node *head_b);
void	rra(t_node *head_a);
void	rrb(t_node *head_b);
void	pa(t_node *head_a, t_node *head_b);
void	pb(t_node *head_a, t_node *head_b);
void	pa_min_and_ra(t_stack *stack, t_node *min);
void	push_min_b(t_stack *stack, t_node *min);
void	pa_harf(t_stack *stack);
void	pb_harf(t_stack *stack);

t_node	*get_min(t_node *head);
t_node	*get_max(t_node *head);
t_node	*get_next_min(t_node *head, t_node *min);
size_t	get_pos(t_node *head, t_node *target);
BOOLEAN	check_sorted(t_node *head);
void	sort_2(t_node *head_a);
void	sort_3(t_node *head_a);
void	sort_4(t_node *head_a, t_node *head_b);
void	sort_5(t_stack *stack);
void	sort_many(t_stack *stack);
void	sort_select(t_stack *stack);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
BOOLEAN	ft_puterr(void);
BOOLEAN	ft_puterr_with_free(t_stack *stack);
int		ft_atoi(const char *nptr);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	**ft_split(char const *s, char c);

BOOLEAN	check_args(size_t size, char **num_list, size_t start);
BOOLEAN	check_duplicate(int argc, char **argv);
BOOLEAN	args_two_exe(char **argv);
BOOLEAN	args_multi_exe(int argc, char **argv);

#endif