#ifndef HAMMER_BATCH_H
#define HAMMER_BATCH_H

#include "hammer_connection.h"

typedef struct hammer_batch_buf_s
{
	// keys, pkt_offsets, and ivs, are all stored in the input buffer
	void *input_buf;

	void *keys;
	uint32_t *pkt_offsets;
	void *ivs;
	
	// GPU output buffer
	void *output_buf;

	// Job for forwarding
	hammer_job_t *job_list;
	int job_num;

	int buf_size;
	int buf_length;
} hammer_batch_buf_t;


/* Each CPU worker holds such a data structure */
typedef struct hammer_batch_s
{
	hammer_batch_buf_t buf_A; // id = 0
	hammer_batch_buf_t buf_B; // id = 1

	hammer_batch_buf_t *cur_buf;
	int cur_buf_id;

	/* GPU worker notify CPU worker 
	 * buf_has_been_taken tell CPU worker which buf has just been taken,
	 * processed_buf_id tell CPU worker which buf has been processed.
	 * they all should be -1, if there are no events.
	 * GPU write it (0/1), and CPU clears it to -1 to claim its own action.
	 */
	int processed_buf_id;
	int buf_has_been_taken;
} hammer_batch_t;

#endif
