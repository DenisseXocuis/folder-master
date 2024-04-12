/* int atender(COLA_PROCESOS *head, int *tiempo) {
    PROCESADOR *procesador_actual = head->frente;
    do {
        if (procesador_actual->TASK != NULL) {
            NODE *tarea_actual = procesador_actual->TASK;
            NODE *primera_tarea = tarea_actual;
            int tareas_atendidas = 0;
            do {
                tarea_actual->t--;

                // Si el tiempo de la tarea llega a cero, eliminar el nodo
                if (tarea_actual->t == 0) {
                    // Si la tarea actual es la única en la cola
                    if (procesador_actual->TASK->next == procesador_actual->TASK) {
                        free(tarea_actual);
                        procesador_actual->TASK = NULL;
                        procesador_actual->contador_procesos--;
                    } else {
                        NODE *temp = tarea_actual->next;
                        while (temp->next != tarea_actual) {
                            temp = temp->next;
                        }
                        temp->next = tarea_actual->next;
                        if (tarea_actual == procesador_actual->TASK) {
                            procesador_actual->TASK = tarea_actual->next;
                        }
                        free(tarea_actual);
                        procesador_actual->contador_procesos--;
                    }
                } else {
                    tarea_actual = tarea_actual->next;
                }

                // Contar las tareas atendidas
                tareas_atendidas++;
            } while (tareas_atendidas < procesador_actual->contador_procesos && tarea_actual != primera_tarea);
        }
        procesador_actual = procesador_actual->next;
    } while (procesador_actual != head->frente);

    return 0;
}
 */