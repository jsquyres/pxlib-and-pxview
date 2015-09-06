#ifndef __PX_HEAD_H__
#define __PX_HEAD_H__
pxhead_t *px_get_head(pxdoc_t *pxdoc, pxstream_t *pxs);
int px_put_head(pxdoc_t *pxdoc, pxhead_t *pxh, pxstream_t *pxs);
int px_put_datablock(pxdoc_t *pxdoc, pxhead_t *pxh, int after, pxstream_t *pxs);
int px_add_data_to_block(pxdoc_t *pxdoc, pxhead_t *pxh, int datablocknr, int recnr, char *data, pxstream_t *pxs, int *update);
int px_delete_data_from_block(pxdoc_t *pxdoc, pxhead_t *pxh, int datablocknr, int recnr, pxstream_t *pxs);
int px_delete_blob_data(pxblob_t *pxblob, int hsize, int size, int bloboffset, int index);
int px_get_datablock_head(pxdoc_t *pxdoc, pxstream_t *pxs, int datablocknr, TDataBlock *datablockhead);

mbhead_t *px_get_mb_head(pxblob_t *pxblob, pxstream_t *pxs);
int px_put_mb_head(pxblob_t *pxblob, mbhead_t *mbh, pxstream_t *pxs);
#endif
