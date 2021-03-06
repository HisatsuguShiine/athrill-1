#include "udp_comm.h"

#define UDP_COMM_BLOCKING		0
#define UDP_COMM_NONBLOCKING	1

Std_ReturnType udp_comm_create_ipaddr(const UdpCommConfigType *config, UdpCommType *comm, const char* my_ipaddr)
{
	int err;
	struct target_os_api_sockaddr_type addr;
	u_long val;

	err = socket(AF_INET, SOCK_DGRAM, 0);
	if (err < 0) {
		return STD_E_INVALID;
	}
	comm->srv_sock = err;

	addr.sin_family = AF_INET;
	addr.sin_port = htons(config->server_port);
	if (my_ipaddr == NULL) {
		addr.sin_addr.target_os_sockaddr_sin_addr = INADDR_ANY;
	}
	else {
		addr.sin_addr.target_os_sockaddr_sin_addr = inet_addr(my_ipaddr);
	}

	err = bind(comm->srv_sock, (struct sockaddr *)&addr, sizeof(addr));
	if (err < 0) {
		return STD_E_INVALID;
	}

	if (!(config->is_wait)) {
		val = UDP_COMM_NONBLOCKING;
	}
	else {
		val = UDP_COMM_BLOCKING;
	}
	target_os_api_ioctlsock(comm->srv_sock, FIONBIO, &val);

	comm->client_port = htons(config->client_port);

	return STD_E_OK;
}
Std_ReturnType udp_comm_create(const UdpCommConfigType *config, UdpCommType *comm)
{
	return udp_comm_create_ipaddr(config, comm, NULL);
}

Std_ReturnType udp_comm_read(UdpCommType *comm)
{
	int err;

	err = recv(comm->srv_sock, comm->read_data.buffer, sizeof(comm->read_data.buffer), 0);
	if (err <= 0) {
		return STD_E_INVALID;
	}
	comm->read_data.len = err;

	return STD_E_OK;
}

Std_ReturnType udp_comm_write(UdpCommType *comm)
{
	int err;
	struct target_os_api_sockaddr_type addr;

	err = socket(AF_INET, SOCK_DGRAM, 0);
	if (err < 0) {
		return STD_E_INVALID;
	}
	comm->clt_sock = err;

	addr.sin_family = AF_INET;
	addr.sin_port = comm->client_port;
	addr.sin_addr.target_os_sockaddr_sin_addr = inet_addr("127.0.0.1");

	err = sendto(comm->clt_sock, comm->write_data.buffer, comm->write_data.len, 0,
			(struct sockaddr *)&addr, sizeof(addr));
	if (err != comm->write_data.len) {
		return STD_E_INVALID;
	}
	target_os_api_closesocket(comm->clt_sock);
	comm->clt_sock = -1;

	return STD_E_OK;
}
Std_ReturnType udp_comm_remote_write(UdpCommType *comm, const char *remote_ipaddr)
{
	int err;
	struct target_os_api_sockaddr_type addr;

	err = socket(AF_INET, SOCK_DGRAM, 0);
	if (err < 0) {
		return STD_E_INVALID;
	}
	comm->clt_sock = err;

	addr.sin_family = AF_INET;
	addr.sin_port = comm->client_port;
	addr.sin_addr.target_os_sockaddr_sin_addr = inet_addr(remote_ipaddr);

	err = sendto(comm->clt_sock, comm->write_data.buffer, comm->write_data.len, 0,
			(struct sockaddr *)&addr, sizeof(addr));
	if (err != comm->write_data.len) {
		return STD_E_INVALID;
	}
	target_os_api_closesocket(comm->clt_sock);
	comm->clt_sock = -1;

	return STD_E_OK;
}

void udp_server_delete(UdpCommType *comm)
{
	target_os_api_closesocket(comm->srv_sock);
	comm->srv_sock = -1;
	return;
}
