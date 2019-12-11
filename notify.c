#include <stdio.h>
#include <stdlib.h>
#include <sys/queue.h>
typedef void qemu_instance_handler(int status);

typedef struct qemu_instance_status_notifilers {
	qemu_instance_handler *cb;
	TAILQ_ENTRY(qemu_instance_status_notifilers) entries;
} qemu_instance_status_notifilers;

static TAILQ_HEAD(, qemu_instance_status_notifilers) qemu_instance_status_notifilers_head;

void qemu_add_instance_status_change_notifier(qemu_instance_handler *cb)
{
	qemu_instance_status_notifilers *e;
	e = malloc(sizeof(*e));

	e->cb = cb;
	//e->opaque = opaque;

	TAILQ_INSERT_TAIL(&qemu_instance_status_notifilers_head, e, entries);
}

void qemu_del_instance_status_change_notifier(qemu_instance_status_notifilers *e)
{
	TAILQ_REMOVE(&qemu_instance_status_notifilers_head, e, entries);
	free(e);
}

void qemu_instance_status_change_notify(int status)
{
	qemu_instance_status_notifilers *e;
	TAILQ_FOREACH(e, &qemu_instance_status_notifilers_head, entries){
		e->cb(status);
	}
}

static void qemu_audio_status_change_handler(int status)
{
	if (status == 1)
		printf("qemu_audio_status_change_handler status = 1 \n");
	else if (status == 0)
		printf("qemu_audio_status_change_handler status = 0 \n");
}

int main()
{
	TAILQ_INIT(&qemu_instance_status_notifilers_head);
	qemu_add_instance_status_change_notifier(qemu_audio_status_change_handler);
	qemu_instance_status_change_notify(1);
}
