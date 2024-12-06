/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhut <vkhut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:28:03 by vkhut             #+#    #+#             */
/*   Updated: 2024/12/06 15:28:03 by vkhut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_split_string(char **split_string)
{
    int i = 0;
    while (split_string[i])
    {
        free(split_string[i]);
        i++;
    }
    free(split_string);
}

t_stack *create_stack(int ac, char **av)
{
    t_stack *stack = NULL;
    t_stack *new_node;
    t_stack *current;
    int i = 1;

    while (i < ac)
    {
        new_node = malloc(sizeof(t_stack));
        if (!new_node)
            return (NULL);
        new_node->value = atoi(av[i]);
        new_node->next = NULL;

        if (stack == NULL)
            stack = new_node;
        else
        {
            current = stack;
            while (current->next)
                current = current->next;
            current->next = new_node;
        }
        i++;
    }

    return stack;
}

void free_stack(t_stack **head)
{
    t_stack *current;
    if (head == NULL)
        return;
    while (*head)
    {
        current = *head;
        *head = (*head)->next;
        free(current);
    }
}

void index_stack(t_stack *head, int l_size)
{
    t_stack *pointer;
    t_stack *largest;
    while (l_size-- > 0)
    {
        pointer = head;
        largest = NULL;
        while (pointer)
        {
            if (!pointer->index && (!largest || pointer->value > largest->value))
                largest = pointer;
            pointer = pointer->next;
        }
        if (largest)
            largest->index = l_size;
    }
    // print_stack(head);
}

int get_node_count(t_stack *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
}

int is_sorted(t_stack *stack)
{
    if (!stack || !stack->next)
    {
        return 1;
    }
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            return 0;
        stack = stack->next;
    }
    return 1;
}

int find_biggest(t_stack *head)
{
    int biggest;
    t_stack *tmp;

    if (!head)
        return -1;

    tmp = head;
    biggest = tmp->value;

    while (tmp)
    {
        if (tmp->value > biggest)
        {
            biggest = tmp->value;
        }
        tmp = tmp->next;
    }

    return biggest;
}

int find_smallest(t_stack *head)
{
    int smallest = head->value;
    t_stack *current = head;

    while (current)
    {
        if (current->value < smallest)
        {
            smallest = current->value;
        }
        current = current->next;
    }

    return smallest;
}

// void print_stack(t_stack *head)
// {
//     while (head)
//     {
//         printf("%d ", head->value);
//         head = head->next;
//     }
//     printf("\n");
// }
