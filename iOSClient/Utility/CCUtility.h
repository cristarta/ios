//
//  CCUtility.h
//  Crypto Cloud Technology Nextcloud
//
//  Created by Marino Faggiana on 02/02/16.
//  Copyright (c) 2014 TWS. All rights reserved.
//
//  Author Marino Faggiana <m.faggiana@twsweb.it>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#import <Foundation/Foundation.h>
#import <MobileCoreServices/MobileCoreServices.h>
#import <sys/utsname.h>
#import <sys/sysctl.h>
#import <AssetsLibrary/AssetsLibrary.h>
#import <MessageUI/MessageUI.h>
#import <UICKeyChainStore/UICKeyChainStore.h>

#import "OCFileDto.h"
#import "CCMetadata.h"
#import "CCCrypto.h"
#import "CCGlobal.h"

@interface CCUtility : NSObject

// ===== KeyChainStore =====

// ADMIN

+ (void)adminRemoveIntro;
+ (void)adminRemovePasscode;
+ (void)adminRemoveVersion;

// SET

+ (void)deleteAllChainStore;

+ (void)storeAllChainInService;

+ (void)setKeyChainPasscodeForUUID:(NSString *)uuid conPasscode:(NSString *)passcode;

+ (NSString *)setVersionCryptoCloud;

+ (void)setBlockCode:(NSString *)blockcode;
+ (void)setSimplyBlockCode:(BOOL)simply;
+ (void)setOnlyLockDir:(BOOL)lockDir;

+ (void)setOptimizedPhoto:(BOOL)resize;
+ (void)setUploadAndRemovePhoto:(BOOL)remove;

+ (void)setOrderSettings:(NSString *)order;
+ (void)setAscendingSettings:(BOOL)ascendente;
+ (void)setGroupBySettings:(NSString *)groupby;

+ (void)setIntro:(NSString *)version;
+ (void)setMessageJailbroken:(BOOL)message;

+ (void)setActiveAccountShareExt:(NSString *)activeAccount;
+ (void)setCryptatedShareExt:(BOOL)cryptated;
+ (void)setServerUrlShareExt:(NSString *)serverUrl;
+ (void)setTitleServerUrlShareExt:(NSString *)titleServerUrl;

+ (void)setEmail:(NSString *)email;

+ (void)setHint:(NSString *)hint;

+ (void)setDirectoryOnTop:(BOOL)directoryOnTop;

+ (void)setFileNameMask:(NSString *)mask key:(NSString *)key;

+ (void)setCreateMenuEncrypted:(BOOL)encrypted;

// GET

+ (NSString *)getKeyChainPasscodeForUUID:(NSString *)uuid;
+ (NSString *)getUUID;
+ (NSString *)getNameCurrentDevice;

+ (NSString *)getVersionCryptoCloud;

+ (NSString *)getBlockCode;
+ (BOOL)getSimplyBlockCode;
+ (BOOL)getOnlyLockDir;

+ (BOOL)getOptimizedPhoto;
+ (BOOL)getUploadAndRemovePhoto;

+ (NSString *)getOrderSettings;
+ (BOOL)getAscendingSettings;
+ (NSString *)getGroupBySettings;

+ (BOOL)getIntro:(NSString *)version;
+ (NSString *)getIncrementalNumber;
+ (BOOL)getMessageJailbroken;

+ (NSString *)getActiveAccountShareExt;
+ (BOOL)getCryptatedShareExt;
+ (NSString *)getServerUrlShareExt;
+ (NSString *)getTitleServerUrlShareExt;

+ (NSString *)getEmail;

+ (NSString *)getHint;

+ (BOOL)getDirectoryOnTop;

+ (NSString *)getFileNameMask:(NSString *)key;

+ (BOOL)getCreateMenuEncrypted;

// ===== Varius =====

+ (NSString *)getUserAgent:(NSString *)typeCloud;

+ (NSString *)dateDiff:(NSDate *) convertedDate;
+ (NSString *)transformedSize:(double)value;

+ (NSString *)removeForbiddenCharacters:(NSString *)fileName hasServerForbiddenCharactersSupport:(BOOL)hasServerForbiddenCharactersSupport;
+ (NSString *)stringAppendServerUrl:(NSString *)serverUrl addServerUrl:(NSString *)addServerUrl;

+ (NSString *)createID;
+ (NSString *)createFileNameFromAsset:(PHAsset *)asset key:(NSString *)key;

+ (NSString *)getHomeServerUrlActiveUrl:(NSString *)activeUrl typeCloud:(NSString *)typeCloud;
+ (NSString *)getDirectoryActiveUser:(NSString *)activeUser activeUrl:(NSString *)activeUrl;
+ (NSString *)getOLDDirectoryActiveUser:(NSString *)activeUser activeUrl:(NSString *)activeUrl;
+ (NSString *)getDirectoryLocal;
+ (NSString *)getDirectoryAudio;
+ (NSString *)getDirectoryCerificates;
+ (NSString *)getTitleSectionDate:(NSDate *)date;

+ (void)moveFileAtPath:(NSString *)atPath toPath:(NSString *)toPath;
+ (void)copyFileAtPath:(NSString *)atPath toPath:(NSString *)toPath;
+ (void)removeAllFileID_UPLOAD_ActiveUser:(NSString *)activeUser activeUrl:(NSString *)activeUrl;

+ (NSString *)deletingLastPathComponentFromServerUrl:(NSString *)serverUrl;
+ (NSString *)returnFileNamePathFromFileName:(NSString *)metadataFileName serverUrl:(NSString *)serverUrl activeUrl:(NSString *)activeUrl typeCloud:(NSString *)typeCloud;

+ (void)sendMailEncryptPass:(NSString *)recipient validateEmail:(BOOL)validateEmail form:(id)form;

+ (NSString *)localizableBrand:(NSString *)localize table:(NSString *)table;

+ (NSArray *)createNameSubFolder:(NSArray *)assets;

// ===== CCMetadata =====

+ (CCMetadata *)trasformedOCFileToCCMetadata:(OCFileDto *)itemDto fileNamePrint:(NSString *)fileNamePrint serverUrl:(NSString *)serverUrl directoryID:(NSString *)directoryID cameraFolderName:(NSString *)cameraFolderName cameraFolderPath:(NSString *)cameraFolderPath activeAccount:(NSString *)activeAccount directoryUser:(NSString *)directoryUser typeCloud:(NSString *)typeCloud;

+ (void)insertTypeFileIconName:(CCMetadata *)metadata directory:(NSString *)directory cameraFolderName:(NSString *)cameraFolderName cameraFolderPath:(NSString *)cameraFolderPath;
+ (void)insertInformationPlist:(CCMetadata *)metadata directoryUser:(NSString *)directoryUser;
+ (CCMetadata *)insertFileSystemInMetadata:(NSString *)fileName directory:(NSString *)directory activeAccount:(NSString *)activeAccount cameraFolderName:(NSString *)cameraFolderName cameraFolderPath:(NSString *)cameraFolderPath;

+ (NSString *)trasformedFileNamePlistInCrypto:(NSString *)fileName;
+ (NSString *)trasformedFileNameCryptoInPlist:(NSString *)fileName;

+ (BOOL)isCryptoString:(NSString *)fileName;
+ (BOOL)isCryptoPlistString:(NSString *)fileName;
+ (BOOL)isFileNotCryptated:(NSString *)filename;
+ (BOOL)isFileCryptated:(NSString *)filename;
+ (NSInteger)getTypeFileName:(NSString *)fileName;

// ===== Third parts =====

+ (NSString *)stringValueForKey:(id)key conDictionary:(NSDictionary *)dictionary;
+ (NSString *)currentDevice;
+ (NSString *)getExtension:(NSString*)fileName;
+ (NSDate*)parseDateString:(NSString*)dateString;
+ (ALAssetsLibrary *)defaultAssetsLibrary;
+ (NSDate *)datetimeWithOutTime:(NSDate *)datDate;
+ (NSDate *)datetimeWithOutDate:(NSDate *)datDate;
+ (BOOL)isValidEmail:(NSString *)checkString;

@end
