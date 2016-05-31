/*
 * Copyright (c) 2016 Hanspeter Portner (dev@open-music-kontrollers.ch)
 *
 * This is free software: you can redistribute it and/or modify
 * it under the terms of the Artistic License 2.0 as published by
 * The Perl Foundation.
 *
 * This source is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * Artistic License 2.0 for more details.
 *
 * You should have received a copy of the Artistic License 2.0
 * along the source as a COPYING file. If not, obtain it from
 * http://www.perlfoundation.org/artistic_license_2_0.
 */

#include <stdlib.h>

#include <alluis.h>

typedef struct _handle_t handle_t;

struct _handle_t {
	const float *input;
	float *output;
};

static LV2_Handle
instantiate(const LV2_Descriptor* descriptor, double rate,
	const char *bundle_path, const LV2_Feature *const *features)
{
	handle_t *handle = calloc(1, sizeof(handle_t));
	if(!handle)
		return NULL;

	return handle;
}

static void
connect_port(LV2_Handle instance, uint32_t port, void *data)
{
	handle_t *handle = instance;

	if(port == 0)
		handle->input = data;
	else if(port == 1)
		handle->output = data;
}

static void
run(LV2_Handle instance, uint32_t nsamples)
{
	handle_t *handle = instance;

	*handle->output = *handle->input;
}

static void
cleanup(LV2_Handle instance)
{
	handle_t *handle = instance;

	free(handle);
}

static const LV2_Descriptor alluis_test_all = {
	.URI						= ALLUIS_TEST_ALL_URI,
	.instantiate		= instantiate,
	.connect_port		= connect_port,
	.activate				= NULL,
	.run						= run,
	.deactivate			= NULL,
	.cleanup				= cleanup,
	.extension_data	= NULL 
};

static const LV2_Descriptor alluis_x11_all = {
	.URI						= ALLUIS_TEST_X11_ONLY_URI,
	.instantiate		= instantiate,
	.connect_port		= connect_port,
	.activate				= NULL,
	.run						= run,
	.deactivate			= NULL,
	.cleanup				= cleanup,
	.extension_data	= NULL 
};

static const LV2_Descriptor alluis_gtk2_all = {
	.URI						= ALLUIS_TEST_GTK2_ONLY_URI,
	.instantiate		= instantiate,
	.connect_port		= connect_port,
	.activate				= NULL,
	.run						= run,
	.deactivate			= NULL,
	.cleanup				= cleanup,
	.extension_data	= NULL 
};

static const LV2_Descriptor alluis_gtk3_all = {
	.URI						= ALLUIS_TEST_GTK3_ONLY_URI,
	.instantiate		= instantiate,
	.connect_port		= connect_port,
	.activate				= NULL,
	.run						= run,
	.deactivate			= NULL,
	.cleanup				= cleanup,
	.extension_data	= NULL 
};

static const LV2_Descriptor alluis_qt4_all = {
	.URI						= ALLUIS_TEST_QT4_ONLY_URI,
	.instantiate		= instantiate,
	.connect_port		= connect_port,
	.activate				= NULL,
	.run						= run,
	.deactivate			= NULL,
	.cleanup				= cleanup,
	.extension_data	= NULL 
};

static const LV2_Descriptor alluis_qt5_all = {
	.URI						= ALLUIS_TEST_QT5_ONLY_URI,
	.instantiate		= instantiate,
	.connect_port		= connect_port,
	.activate				= NULL,
	.run						= run,
	.deactivate			= NULL,
	.cleanup				= cleanup,
	.extension_data	= NULL 
};

static const LV2_Descriptor alluis_show_all = {
	.URI						= ALLUIS_TEST_SHOW_ONLY_URI,
	.instantiate		= instantiate,
	.connect_port		= connect_port,
	.activate				= NULL,
	.run						= run,
	.deactivate			= NULL,
	.cleanup				= cleanup,
	.extension_data	= NULL 
};

static const LV2_Descriptor alluis_kx_all = {
	.URI						= ALLUIS_TEST_KX_ONLY_URI,
	.instantiate		= instantiate,
	.connect_port		= connect_port,
	.activate				= NULL,
	.run						= run,
	.deactivate			= NULL,
	.cleanup				= cleanup,
	.extension_data	= NULL 
};

static const LV2_Descriptor alluis_eo_all = {
	.URI						= ALLUIS_TEST_EO_ONLY_URI,
	.instantiate		= instantiate,
	.connect_port		= connect_port,
	.activate				= NULL,
	.run						= run,
	.deactivate			= NULL,
	.cleanup				= cleanup,
	.extension_data	= NULL 
};

#ifdef _WIN32
__declspec(dllexport)
#else
__attribute__((visibility("default")))
#endif
const LV2_Descriptor*
lv2_descriptor(uint32_t index)
{
	switch(index)
	{
		case 0:
			return &alluis_test_all;
		case 1:
			return &alluis_x11_all;
		case 2:
			return &alluis_gtk2_all;
		case 3:
			return &alluis_gtk3_all;
		case 4:
			return &alluis_qt4_all;
		case 5:
			return &alluis_qt5_all;
		case 6:
			return &alluis_show_all;
		case 7:
			return &alluis_kx_all;
		case 8:
			return &alluis_eo_all;

		default:
			return NULL;
	}
}
