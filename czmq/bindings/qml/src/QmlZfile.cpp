/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/

#include "QmlZfile.h"


///
//  Duplicate a file item, returns a newly constructed item. If the file
//  is null, or memory was exhausted, returns null.                     
QmlZfile *QmlZfile::dup () {
    QmlZfile *retQ_ = new QmlZfile ();
    retQ_->self = zfile_dup (self);
    return retQ_;
};

///
//  Return file name, remove path if provided
const QString QmlZfile::filename (const QString &path) {
    return QString (zfile_filename (self, path.toUtf8().data()));
};

///
//  Refresh file properties from disk; this is not done automatically   
//  on access methods, otherwise it is not possible to compare directory
//  snapshots.                                                          
void QmlZfile::restat () {
    zfile_restat (self);
};

///
//  Return when the file was last modified. If you want this to reflect the
//  current situation, call zfile_restat before checking this property.    
time_t QmlZfile::modified () {
    return zfile_modified (self);
};

///
//  Return the last-known size of the file. If you want this to reflect the
//  current situation, call zfile_restat before checking this property.    
off_t QmlZfile::cursize () {
    return zfile_cursize (self);
};

///
//  Return true if the file is a directory. If you want this to reflect   
//  any external changes, call zfile_restat before checking this property.
bool QmlZfile::isDirectory () {
    return zfile_is_directory (self);
};

///
//  Return true if the file is a regular file. If you want this to reflect
//  any external changes, call zfile_restat before checking this property.
bool QmlZfile::isRegular () {
    return zfile_is_regular (self);
};

///
//  Return true if the file is readable by this process. If you want this to
//  reflect any external changes, call zfile_restat before checking this    
//  property.                                                               
bool QmlZfile::isReadable () {
    return zfile_is_readable (self);
};

///
//  Return true if the file is writeable by this process. If you want this 
//  to reflect any external changes, call zfile_restat before checking this
//  property.                                                              
bool QmlZfile::isWriteable () {
    return zfile_is_writeable (self);
};

///
//  Check if file has stopped changing and can be safely processed.
//  Updates the file statistics from disk at every call.           
bool QmlZfile::isStable () {
    return zfile_is_stable (self);
};

///
//  Return true if the file was changed on disk since the zfile_t object
//  was created, or the last zfile_restat() call made on it.            
bool QmlZfile::hasChanged () {
    return zfile_has_changed (self);
};

///
//  Remove the file from disk
void QmlZfile::remove () {
    zfile_remove (self);
};

///
//  Open file for reading                             
//  Returns 0 if OK, -1 if not found or not accessible
int QmlZfile::input () {
    return zfile_input (self);
};

///
//  Open file for writing, creating directory if needed               
//  File is created if necessary; chunks can be written to file at any
//  location. Returns 0 if OK, -1 if error.                           
int QmlZfile::output () {
    return zfile_output (self);
};

///
//  Read chunk from file at specified position. If this was the last chunk,
//  sets the eof property. Returns a null chunk in case of error.          
QmlZchunk *QmlZfile::read (size_t bytes, off_t offset) {
    QmlZchunk *retQ_ = new QmlZchunk ();
    retQ_->self = zfile_read (self, bytes, offset);
    return retQ_;
};

///
//  Returns true if zfile_read() just read the last chunk in the file.
bool QmlZfile::eof () {
    return zfile_eof (self);
};

///
//  Write chunk to file at specified position
//  Return 0 if OK, else -1                  
int QmlZfile::write (QmlZchunk *chunk, off_t offset) {
    return zfile_write (self, chunk->self, offset);
};

///
//  Read next line of text from file. Returns a pointer to the text line,
//  or NULL if there was nothing more to read from the file.             
const QString QmlZfile::readln () {
    return QString (zfile_readln (self));
};

///
//  Close file, if open
void QmlZfile::close () {
    zfile_close (self);
};

///
//  Return file handle, if opened
FILE *QmlZfile::handle () {
    return zfile_handle (self);
};

///
//  Calculate SHA1 digest for file, using zdigest class.
const QString QmlZfile::digest () {
    return QString (zfile_digest (self));
};


QObject* QmlZfile::qmlAttachedProperties(QObject* object) {
    return new QmlZfileAttached(object);
}


///
//  Self test of this class.
void QmlZfileAttached::test (bool verbose) {
    zfile_test (verbose);
};

///
//  If file exists, populates properties. CZMQ supports portable symbolic
//  links, which are files with the extension ".ln". A symbolic link is a
//  text file containing one line, the filename of a target file. Reading
//  data from the symbolic link actually reads from the target file. Path
//  may be NULL, in which case it is not used.                           
QmlZfile *QmlZfileAttached::construct (const QString &path, const QString &name) {
    QmlZfile *qmlSelf = new QmlZfile ();
    qmlSelf->self = zfile_new (path.toUtf8().data(), name.toUtf8().data());
    return qmlSelf;
};

///
//  Destroy a file item
void QmlZfileAttached::destruct (QmlZfile *qmlSelf) {
    zfile_destroy (&qmlSelf->self);
};

/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/
