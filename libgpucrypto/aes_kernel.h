#ifndef __AES_KERNEL__
#define __AES_KERNEL__

#include <stdint.h>
#include <cuda_runtime.h>

void AES_cbc_128_encrypt_gpu(const uint8_t *in_d,
			     uint8_t *out_d,
			     const uint32_t* pkt_offset_d,
			     const uint8_t *keys_d,
			     uint8_t *ivs_d,
			     const unsigned int numFlows,
			     uint8_t *checkbits_d,
			     const unsigned int threads_per_blk,
			     cudaStream_t stream = 0);
#endif /* __AES_KERNEL__ */
