px4_add_module(
	MODULE modules__recovery
	MAIN recovery
	STACK 2000
	SRCS
		recovery.cpp
	DEPENDS
		platforms__common
	)
