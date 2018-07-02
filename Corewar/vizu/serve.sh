# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    serve.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/01 21:07:11 by pde-rent          #+#    #+#              #
#    Updated: 2018/07/01 21:59:08 by pde-rent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

killall Python
killall Python3
nohup python3 file_server.py >/dev/null 2>&1 &
nohup python3 websocket_pipe.py >/dev/null 2>&1 &
nohup python3 socket_bridge.py >/dev/null 2>&1 &
#nohup python3 file_server.py
#nohup python3 websocket_pipe.py
#nohup python3 socket_bridge.py
