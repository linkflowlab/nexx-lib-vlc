#include <stdio.h>
#include <stdlib.h>

#include <vlc/vlc.h>

int main(int argc, char **argv)
{
    libvlc_instance_t *inst;
    libvlc_media_player_t *mp;
    libvlc_media_t *m;

	static const char* const args[] = {
//		"--video-filter", "stitching"
	};

    // load the vlc engine
    inst = libvlc_new(sizeof args/ sizeof *args, args);

    // create a new item
    m = libvlc_media_new_path(inst, "/home/dragon/project/fitt360-app-security/input/tc1/leftfront.avi");
	//m = libvlc_media_new_path(inst, "/home/dragon/VID_20180112_172426.mp4");

    // create a media play playing environment
    mp = libvlc_media_player_new_from_media(m);

    // no need to keep the media now
    libvlc_media_release(m);

    // play the media_player
    libvlc_media_player_play(mp);

	// test hand-made APIs
	// 1. stitching API
	libvlc_video_set_stitching(mp, 1);
	sleep(2);
	libvlc_video_set_stitching(mp, 0);
	sleep(2);

	// 2. filter API
	libvlc_set_video_filters_string(mp, "video-filter", "mirror:invert");
	sleep(2);
	libvlc_set_video_filters_string(mp, "video-filter", "mirror");
	sleep(2);
	libvlc_set_video_filters_string(mp, "video-filter", "");
	sleep(2);
	libvlc_set_video_filters_string(mp, "video-filter", "stitching");

	sleep(30);

    // stop playing
    libvlc_media_player_stop(mp);

    // free the media_player
    libvlc_media_player_release(mp);

    libvlc_release(inst);


    return 0;
}
