/*
 * Copyright 2000, International Business Machines Corporation and others.
 * All Rights Reserved.
 *
 * This software has been released under the terms of the IBM Public
 * License.  For details, see the LICENSE file in the top-level source
 * directory or online at http://www.openafs.org/dl/license10.html
 */

#ifndef	AFS_SRC_VOLSER_INTERNAL_H
#define AFS_SRC_VOLSER_INTERNAL_H

/* common.c */
extern void Abort(const char *, ...) AFS_NORETURN AFS_ATTRIBUTE_FORMAT(__printf__, 1, 2);
extern void Log(const char *, ...) AFS_ATTRIBUTE_FORMAT(__printf__, 1, 2);
extern void InitErrTabs(void);

/* vol_split.c */
extern afs_int32 split_volume(struct rx_call *, Volume *, Volume *,
			      afs_uint32, afs_int32);

/* voltrans.c */
extern struct volser_trans *FindTrans(afs_int32);
extern struct volser_trans *NewTrans(VolumeId, afs_int32);
extern struct volser_trans *TransList(void);
extern afs_int32 DeleteTrans(struct volser_trans *atrans, afs_int32 lock);
extern afs_int32 TRELE (struct volser_trans *);

/* volprocs.c */
extern int VPFullUnlock(void);

/* voltrans.c */
extern afs_int32 GCTrans(void);

/* vsprocs.c */
struct nvldbentry;
extern int PrintError(char *msg, afs_int32 errcode);
extern void init_volintInfo(struct volintInfo *vinfo);
extern void SubEnumerateEntry(struct nvldbentry *entry);
extern void EnumerateEntry(struct nvldbentry *entry);
extern int vs_DeleteVolume(afs_uint32 aserver, afs_int32 apart,
			   afs_uint32 avolid);
extern int vs_ListOneVolume(afs_uint32 aserver, afs_int32 apart,
			    afs_uint32 volid, struct volintInfo **resultPtr);
extern int vs_PartitionInfo64(struct rx_connection *aconn, char *pname,
			      struct diskPartition64 *partition);
extern int vs_CreateVolume(afs_uint32 aserver, afs_int32 apart, char *aname,
			    afs_int32 aquota, afs_int32 aspare1,
			    afs_int32 aspare2, afs_int32 aspare3,
			    afs_int32 aspare4, afs_uint32 * anewid,
			    afs_uint32 * aroid, afs_uint32 * abkid);
extern int vs_AddVLDBEntry(afs_uint32 aserver, afs_int32 apart, char *aname,
			   afs_uint32 aid);
extern int vs_MoveVolume(afs_uint32 afromvol, afs_uint32 afromserver,
                          afs_int32 afrompart, afs_uint32 atoserver,
                          afs_int32 atopart, int flags);
extern int vs_BackupVolume(afs_uint32 aserver, afs_int32 apart,
			   afs_uint32 avolid);
extern int vs_ReleaseVolume(afs_uint32 afromvol, afs_uint32 afromserver,
			    afs_int32 afrompart, int flags);
extern int vs_DumpVolume(afs_uint32 afromvol, afs_uint32 afromserver,
			 afs_int32 afrompart, afs_int32 fromdate,
			 afs_int32(*DumpFunction) (struct rx_call *, void *),
			 void *rock, afs_int32 flags);
extern int vs_RestoreVolume(afs_uint32 toserver, afs_int32 topart,
			     afs_uint32 tovolid, afs_uint32 toparentid,
			     char tovolname[], int flags,
                             afs_int32(*WriteData) (struct rx_call *, void *),
			     void *rock);
extern int vs_LockRelease(afs_uint32 volid);
extern int vs_AddSite(afs_uint32 server, afs_int32 part, afs_uint32 volid,
		       afs_uint32 rovolid, afs_int32 valid);
extern int vs_RemoveSite(afs_uint32 server, afs_int32 part, afs_uint32 volid);
extern int vs_ChangeLocation(afs_uint32 server, afs_int32 part,
			     afs_uint32 volid);
extern int vs_ListPartitions(struct rx_connection *conn, struct partList *ptrPartList,
			     afs_int32 * cntp);
extern int vs_ZapVolumeClones(afs_uint32 aserver, afs_int32 apart,
			      struct volDescription *volPtr,
			      afs_int32 arraySize);
extern int vs_GenerateVolumeClones(afs_uint32 aserver, afs_int32 apart,
				   struct volDescription *volPtr,
				   afs_int32 arraySize);
extern int vs_ListVolumes(afs_uint32 aserver, afs_int32 apart, int all,
			  struct volintInfo **resultPtr, afs_int32 * size);
extern int vs_XListVolumes(afs_uint32 a_serverID, afs_int32 a_partID,
			   int a_all, struct volintXInfo **a_resultPP,
			   afs_int32 * a_numEntsInResultP);
extern int vs_XListOneVolume(afs_uint32 a_serverID, afs_int32 a_partID,
			     afs_uint32 a_volID,
			     struct volintXInfo **a_resultPP);
extern int vs_SyncVolume(afs_uint32 aserver, afs_int32 apart, char *avolname,
			 int flags);
extern int vs_SyncVldb(afs_uint32 aserver, afs_int32 apart, int flags,
		       int force);
extern int vs_SyncServer(afs_uint32 aserver, afs_int32 apart, int flags,
			 int force);
extern int vs_RenameVolume(struct nvldbentry *entry, char oldname[],
			   char newname[]);
extern int vs_VolserStatus(afs_uint32 server, transDebugInfo ** rpntr,
			   afs_int32 * rcount);
extern int vs_VolumeZap(afs_uint32 server, afs_int32 part, afs_uint32 volid);
extern int vs_SetVolume(afs_uint32 server, afs_int32 partition,
			afs_uint32 volid, afs_int32 transflag,
			afs_int32 setflag, int sleeptime);
extern int vs_SetVolumeInfo(afs_uint32 server, afs_int32 partition,
			    afs_uint32 volid, volintInfo * infop);
extern void MapNetworkToHost(struct nvldbentry *old, struct nvldbentry *new);
extern int vs_CopyVolume(afs_uint32 afromvol, afs_uint32 afromserver,
                          afs_int32 afrompart, char *atovolname,
                          afs_uint32 atoserver, afs_int32 atopart,
                          afs_uint32 atovolid, int flags);
extern int vs_CloneVolume(afs_uint32 aserver, afs_int32 apart, afs_uint32 avolid,
                          afs_uint32 acloneid, char *aname, int flags);
extern int vs_DumpClonedVolume(afs_uint32 afromvol, afs_uint32 afromserver,
                               afs_int32 afrompart, afs_int32 fromdate,
                               afs_int32(*DumpFunction)
					  (struct rx_call *, void *),
			       void *rock, afs_int32 flags);
extern int vs_GetSize(afs_uint32 afromvol, afs_uint32 afromserver,
                      afs_int32 afrompart, afs_int32 fromdate,
                      struct volintSize *vol_size);
extern int vs_ConvertRO(afs_uint32 server, afs_uint32 partition, afs_uint32 volid,
			struct nvldbentry *entry);
extern int verbose;
extern int noresolve;
#endif
