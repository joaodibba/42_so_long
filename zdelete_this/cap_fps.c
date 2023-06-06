/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cap_fps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:50:21 by jalves-c          #+#    #+#             */
/*   Updated: 2023/06/01 19:35:23 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>

void cap_fps(int cap)
{
	struct timeval time;
	
	const int FPS_CAP = cap;
    const int US_PER_FRAME = 1000000 / FPS_CAP;
    static struct timeval last_frame_time = {0};
    gettimeofday(&time, NULL);
    long elapsed_time = (time.tv_sec - last_frame_time.tv_sec) * 1000000 +
                         time.tv_usec - last_frame_time.tv_usec;
    if (elapsed_time < US_PER_FRAME) {
        usleep(US_PER_FRAME - elapsed_time);
    }
    last_frame_time = time;
}