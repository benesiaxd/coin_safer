ta include headers
	tee_api.h
	tee_api_defines.h
	tee_api_types.h
	tee_ta_api.h
	trace.h
	tee_api_defines_extensions.h

host include headers
	tee_client_api.h
	/*ONLY using macro*/
	hello_world_ta.h	-> ./ta/include


KEEP_ALIVE : file descript stay opened
# optee_example_hello_world			-->first execution
	Invoking TA to increment 42
	TA incremented value to 43
	Init: 0.002542 seconds
	OpenSession: 0.326999 seconds
	last: 0.352198 seconds
# optee_example_hello_world			-->second execution
	Invoking TA to increment 42
	TA incremented value to 43
	Init: 0.002077 seconds
	OpenSession: 0.006698 seconds
	last: 0.044699 seconds


In TA window
#first execution
#optee_os/core/kernel/pseudo_ta.c
	D/TC:? 0 tee_ta_init_pseudo_ta_session:299 Lookup pseudo TA 8aaaf200-2450-11e4-abe2-0002a5d5c51b
	D/TC:? 0 ldelf_load_ldelf:91 ldelf load address 0x40006000
	D/LD:  ldelf:134 Loading TS 8aaaf200-2450-11e4-abe2-0002a5d5c51b
	D/TC:? 0 ldelf_syscall_open_bin:142 Lookup user TA ELF 8aaaf200-2450-11e4-abe2-0002a5d5c51b (Secure Storage TA)
	D/TC:? 0 ldelf_syscall_open_bin:146 res=0xffff0008
	D/TC:? 0 ldelf_syscall_open_bin:142 Lookup user TA ELF 8aaaf200-2450-11e4-abe2-0002a5d5c51b (REE)
	D/TC:? 0 ldelf_syscall_open_bin:146 res=0
	D/LD:  ldelf:168 ELF (8aaaf200-2450-11e4-abe2-0002a5d5c51b) at 0x4007f000
	D/TA:  TA_CreateEntryPoint:39 has been called
	D/TA:  TA_OpenSessionEntryPoint:74 has been called
	I/TA: Hello World!
	I/TA: start: 66.471(s), stop: 66.477(s)
	D/TA:  inc_value:117 has been called
	I/TA: Got value: 42 from NW
	I/TA: Increase value to: 43
	D/TC:? 0 tee_ta_close_session:512 csess 0x8ac03840 id 1
	D/TC:? 0 tee_ta_close_session:531 Destroy session
	I/TA: Goodbye!

#seconds execution
#optee_os/core/kernel/tee_ta_manager.c
	D/TC:? 0 tee_ta_init_session_with_context:607 Re-open TA 8aaaf200-2450-11e4-abe2-0002a5d5c51b
	D/TA:  TA_OpenSessionEntryPoint:74 has been called
	I/TA: Hello World!
	I/TA: start: 188.411(s), stop: 188.413(s)
	D/TA:  inc_value:117 has been called
	I/TA: Got value: 42 from NW
	I/TA: Increase value to: 43
	D/TC:? 0 tee_ta_close_session:512 csess 0x8ac02310 id 1
	D/TC:? 0 tee_ta_close_session:531 Destroy session
	I/TA: Goodbye!



================
????????? ???????????? tee_ta_open_session??? ???????????????
core/tee/tee_svc.c
core/tee/entry_std.c

====core/kernel/tee_ta_manager.c====
1.tee_ta_open_session : tee_ta_init_session ??????

2.tee_ta_init_session : call ?????? ??????????????? 
	tee_ta_init_pseudo_ta_session?????? tee_ta_init_session_with_context??? ??????

3. tee_ta_close_session : ?????? TA??? ????????? ????????? ??????

4. destroy_context	: context??? ??????
		??? ????????? ?????? ???????????? context ??? ???????????? ???????????????????
		condvar_destroy(&ctx->busy_cv);
		pgt_flush_ctx(&ctx->ts_ctx);
		ctx->ts_ctx.ops->destroy(&ctx->ts_ctx);

==============
OpenSession ?????? ?????? ????????????????
ioctl : open tee and write buffer 
	Takes a struct tee_ioctl_buf_data which contains a struct tee_ioctl_open_session_arg followed by any array of struct tee_ioctl_param.

