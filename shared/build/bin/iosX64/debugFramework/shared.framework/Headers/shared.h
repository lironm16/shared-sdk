#import <Foundation/NSArray.h>
#import <Foundation/NSDictionary.h>
#import <Foundation/NSError.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSSet.h>
#import <Foundation/NSString.h>
#import <Foundation/NSValue.h>

@class SharedKotlinEnumCompanion, SharedKotlinEnum<E>, SharedAdFormatCompanion, SharedAdFormat, SharedKotlinArray<T>, SharedCalculatorCompanion, SharedCappingStatus, SharedCappingType, SharedCappingTimeUnitCompanion, SharedCappingTimeUnit, SharedCappingService, SharedDeliveryHandler, SharedPacingCappingConfig, SharedShowCountCappingConfig, SharedLevelPlayReward;

@protocol SharedKotlinComparable, SharedPlatform, SharedICappingService, SharedICappingConfigProvider, SharedICappingServiceEditor, SharedCurrentTimeProvider, SharedDataStorage, SharedIPlacementCappingService, SharedIPlacementCappingServiceEditor, SharedICappingConfigValidator, SharedIPacingDataRepository, SharedIShowCountDataRepository, SharedIRewardService, SharedIRewardServiceEditor, SharedKotlinIterator;

NS_ASSUME_NONNULL_BEGIN
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#pragma clang diagnostic ignored "-Wincompatible-property-type"
#pragma clang diagnostic ignored "-Wnullability"

#pragma push_macro("_Nullable_result")
#if !__has_feature(nullability_nullable_result)
#undef _Nullable_result
#define _Nullable_result _Nullable
#endif

__attribute__((swift_name("KotlinBase")))
@interface SharedBase : NSObject
- (instancetype)init __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (void)initialize __attribute__((objc_requires_super));
@end

@interface SharedBase (SharedBaseCopying) <NSCopying>
@end

__attribute__((swift_name("KotlinMutableSet")))
@interface SharedMutableSet<ObjectType> : NSMutableSet<ObjectType>
@end

__attribute__((swift_name("KotlinMutableDictionary")))
@interface SharedMutableDictionary<KeyType, ObjectType> : NSMutableDictionary<KeyType, ObjectType>
@end

@interface NSError (NSErrorSharedKotlinException)
@property (readonly) id _Nullable kotlinException;
@end

__attribute__((swift_name("KotlinNumber")))
@interface SharedNumber : NSNumber
- (instancetype)initWithChar:(char)value __attribute__((unavailable));
- (instancetype)initWithUnsignedChar:(unsigned char)value __attribute__((unavailable));
- (instancetype)initWithShort:(short)value __attribute__((unavailable));
- (instancetype)initWithUnsignedShort:(unsigned short)value __attribute__((unavailable));
- (instancetype)initWithInt:(int)value __attribute__((unavailable));
- (instancetype)initWithUnsignedInt:(unsigned int)value __attribute__((unavailable));
- (instancetype)initWithLong:(long)value __attribute__((unavailable));
- (instancetype)initWithUnsignedLong:(unsigned long)value __attribute__((unavailable));
- (instancetype)initWithLongLong:(long long)value __attribute__((unavailable));
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value __attribute__((unavailable));
- (instancetype)initWithFloat:(float)value __attribute__((unavailable));
- (instancetype)initWithDouble:(double)value __attribute__((unavailable));
- (instancetype)initWithBool:(BOOL)value __attribute__((unavailable));
- (instancetype)initWithInteger:(NSInteger)value __attribute__((unavailable));
- (instancetype)initWithUnsignedInteger:(NSUInteger)value __attribute__((unavailable));
+ (instancetype)numberWithChar:(char)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedChar:(unsigned char)value __attribute__((unavailable));
+ (instancetype)numberWithShort:(short)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedShort:(unsigned short)value __attribute__((unavailable));
+ (instancetype)numberWithInt:(int)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedInt:(unsigned int)value __attribute__((unavailable));
+ (instancetype)numberWithLong:(long)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedLong:(unsigned long)value __attribute__((unavailable));
+ (instancetype)numberWithLongLong:(long long)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value __attribute__((unavailable));
+ (instancetype)numberWithFloat:(float)value __attribute__((unavailable));
+ (instancetype)numberWithDouble:(double)value __attribute__((unavailable));
+ (instancetype)numberWithBool:(BOOL)value __attribute__((unavailable));
+ (instancetype)numberWithInteger:(NSInteger)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedInteger:(NSUInteger)value __attribute__((unavailable));
@end

__attribute__((swift_name("KotlinByte")))
@interface SharedByte : SharedNumber
- (instancetype)initWithChar:(char)value;
+ (instancetype)numberWithChar:(char)value;
@end

__attribute__((swift_name("KotlinUByte")))
@interface SharedUByte : SharedNumber
- (instancetype)initWithUnsignedChar:(unsigned char)value;
+ (instancetype)numberWithUnsignedChar:(unsigned char)value;
@end

__attribute__((swift_name("KotlinShort")))
@interface SharedShort : SharedNumber
- (instancetype)initWithShort:(short)value;
+ (instancetype)numberWithShort:(short)value;
@end

__attribute__((swift_name("KotlinUShort")))
@interface SharedUShort : SharedNumber
- (instancetype)initWithUnsignedShort:(unsigned short)value;
+ (instancetype)numberWithUnsignedShort:(unsigned short)value;
@end

__attribute__((swift_name("KotlinInt")))
@interface SharedInt : SharedNumber
- (instancetype)initWithInt:(int)value;
+ (instancetype)numberWithInt:(int)value;
@end

__attribute__((swift_name("KotlinUInt")))
@interface SharedUInt : SharedNumber
- (instancetype)initWithUnsignedInt:(unsigned int)value;
+ (instancetype)numberWithUnsignedInt:(unsigned int)value;
@end

__attribute__((swift_name("KotlinLong")))
@interface SharedLong : SharedNumber
- (instancetype)initWithLongLong:(long long)value;
+ (instancetype)numberWithLongLong:(long long)value;
@end

__attribute__((swift_name("KotlinULong")))
@interface SharedULong : SharedNumber
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value;
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value;
@end

__attribute__((swift_name("KotlinFloat")))
@interface SharedFloat : SharedNumber
- (instancetype)initWithFloat:(float)value;
+ (instancetype)numberWithFloat:(float)value;
@end

__attribute__((swift_name("KotlinDouble")))
@interface SharedDouble : SharedNumber
- (instancetype)initWithDouble:(double)value;
+ (instancetype)numberWithDouble:(double)value;
@end

__attribute__((swift_name("KotlinBoolean")))
@interface SharedBoolean : SharedNumber
- (instancetype)initWithBool:(BOOL)value;
+ (instancetype)numberWithBool:(BOOL)value;
@end

__attribute__((swift_name("KotlinComparable")))
@protocol SharedKotlinComparable
@required
- (int32_t)compareToOther:(id _Nullable)other __attribute__((swift_name("compareTo(other:)")));
@end

__attribute__((swift_name("KotlinEnum")))
@interface SharedKotlinEnum<E> : SharedBase <SharedKotlinComparable>
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) SharedKotlinEnumCompanion *companion __attribute__((swift_name("companion")));
- (int32_t)compareToOther:(E)other __attribute__((swift_name("compareTo(other:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) int32_t ordinal __attribute__((swift_name("ordinal")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AdFormat")))
@interface SharedAdFormat : SharedKotlinEnum<SharedAdFormat *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) SharedAdFormatCompanion *companion __attribute__((swift_name("companion")));
@property (class, readonly) SharedAdFormat *banner __attribute__((swift_name("banner")));
@property (class, readonly) SharedAdFormat *interstitial __attribute__((swift_name("interstitial")));
@property (class, readonly) SharedAdFormat *rewarded __attribute__((swift_name("rewarded")));
@property (class, readonly) SharedAdFormat *nativeAd __attribute__((swift_name("nativeAd")));
+ (SharedKotlinArray<SharedAdFormat *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<SharedAdFormat *> *entries __attribute__((swift_name("entries")));
@property (readonly) NSString *value __attribute__((swift_name("value")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AdFormat.Companion")))
@interface SharedAdFormatCompanion : SharedBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) SharedAdFormatCompanion *shared __attribute__((swift_name("shared")));
- (SharedAdFormat * _Nullable)fromValueValue:(NSString *)value __attribute__((swift_name("fromValue(value:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Calculator")))
@interface SharedCalculator : SharedBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@property (class, readonly, getter=companion) SharedCalculatorCompanion *companion __attribute__((swift_name("companion")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Calculator.Companion")))
@interface SharedCalculatorCompanion : SharedBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) SharedCalculatorCompanion *shared __attribute__((swift_name("shared")));
- (int32_t)sumA:(int32_t)a b:(int32_t)b __attribute__((swift_name("sum(a:b:)")));
@end

__attribute__((swift_name("CurrentTimeProvider")))
@protocol SharedCurrentTimeProvider
@required
- (int64_t)nowInMilliseconds __attribute__((swift_name("nowInMilliseconds()")));
@end

__attribute__((swift_name("DataStorage")))
@protocol SharedDataStorage
@required
- (BOOL)getBoolKey:(NSString *)key __attribute__((swift_name("getBool(key:)")));
- (id _Nullable)getObjectKey:(NSString *)key __attribute__((swift_name("getObject(key:)")));
- (NSString * _Nullable)getStringKey:(NSString *)key __attribute__((swift_name("getString(key:)")));
- (void)removeObjectKey:(NSString *)key __attribute__((swift_name("removeObject(key:)")));
- (void)setValue:(id _Nullable)value key:(NSString *)key __attribute__((swift_name("set(value:key:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Greeting")))
@interface SharedGreeting : SharedBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (NSString *)greeting __attribute__((swift_name("greeting()")));
@end

__attribute__((swift_name("Platform")))
@protocol SharedPlatform
@required
@property (readonly) NSString *platform __attribute__((swift_name("platform")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("IOSPlatform")))
@interface SharedIOSPlatform : SharedBase <SharedPlatform>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@property (readonly) NSString *platform __attribute__((swift_name("platform")));
@end

__attribute__((swift_name("ICappingService")))
@protocol SharedICappingService
@required
- (SharedCappingStatus *)cappingStatusIdentifier:(NSString *)identifier __attribute__((swift_name("cappingStatus(identifier:)")));
@end

__attribute__((swift_name("ICappingServiceEditor")))
@protocol SharedICappingServiceEditor
@required
- (id _Nullable)addConfigIdentifier:(NSString *)identifier cappingType:(SharedCappingType *)cappingType cappingConfig:(id<SharedICappingConfigProvider>)cappingConfig __attribute__((swift_name("addConfig(identifier:cappingType:cappingConfig:)")));
- (void)updateCappingOnShowIdentifier:(NSString *)identifier __attribute__((swift_name("updateCappingOnShow(identifier:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CappingService")))
@interface SharedCappingService : SharedBase <SharedICappingService, SharedICappingServiceEditor>
- (instancetype)initWithCurrentTimeProvider:(id<SharedCurrentTimeProvider>)currentTimeProvider dataStorage:(id<SharedDataStorage>)dataStorage __attribute__((swift_name("init(currentTimeProvider:dataStorage:)"))) __attribute__((objc_designated_initializer));

/**
 * @note annotations
 *   kotlin.jvm.Synchronized
*/
- (id _Nullable)addConfigIdentifier:(NSString *)identifier cappingType:(SharedCappingType *)cappingType cappingConfig:(id<SharedICappingConfigProvider>)cappingConfig __attribute__((swift_name("addConfig(identifier:cappingType:cappingConfig:)")));

/**
 * @note annotations
 *   kotlin.jvm.Synchronized
*/
- (SharedCappingStatus *)cappingStatusIdentifier:(NSString *)identifier __attribute__((swift_name("cappingStatus(identifier:)")));

/**
 * @note annotations
 *   kotlin.jvm.Synchronized
*/
- (void)updateCappingOnShowIdentifier:(NSString *)identifier __attribute__((swift_name("updateCappingOnShow(identifier:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CappingStatus")))
@interface SharedCappingStatus : SharedBase
- (instancetype)initWithIsCapped:(BOOL)isCapped type:(SharedCappingType * _Nullable)type __attribute__((swift_name("init(isCapped:type:)"))) __attribute__((objc_designated_initializer));
- (SharedCappingStatus *)doCopyIsCapped:(BOOL)isCapped type:(SharedCappingType * _Nullable)type __attribute__((swift_name("doCopy(isCapped:type:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString * _Nullable)reason __attribute__((swift_name("reason()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) BOOL isCapped __attribute__((swift_name("isCapped")));
@property (readonly) SharedCappingType * _Nullable type __attribute__((swift_name("type")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CappingTimeUnit")))
@interface SharedCappingTimeUnit : SharedKotlinEnum<SharedCappingTimeUnit *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) SharedCappingTimeUnitCompanion *companion __attribute__((swift_name("companion")));
@property (class, readonly) SharedCappingTimeUnit *day __attribute__((swift_name("day")));
@property (class, readonly) SharedCappingTimeUnit *hour __attribute__((swift_name("hour")));
@property (class, readonly) SharedCappingTimeUnit *second __attribute__((swift_name("second")));
+ (SharedKotlinArray<SharedCappingTimeUnit *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<SharedCappingTimeUnit *> *entries __attribute__((swift_name("entries")));
- (int64_t)inMillisecondsDuration:(SharedInt * _Nullable)duration __attribute__((swift_name("inMilliseconds(duration:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CappingTimeUnit.Companion")))
@interface SharedCappingTimeUnitCompanion : SharedBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) SharedCappingTimeUnitCompanion *shared __attribute__((swift_name("shared")));
- (SharedCappingTimeUnit * _Nullable)fromStringValue:(NSString * _Nullable)value __attribute__((swift_name("fromString(value:)")));
@end

__attribute__((swift_name("IPlacementCappingService")))
@protocol SharedIPlacementCappingService
@required
- (SharedCappingStatus *)cappingStatusPlacementName:(NSString *)placementName adFormat:(SharedAdFormat *)adFormat __attribute__((swift_name("cappingStatus(placementName:adFormat:)")));
@end

__attribute__((swift_name("IPlacementCappingServiceEditor")))
@protocol SharedIPlacementCappingServiceEditor
@required
- (id _Nullable)addConfigPlacementName:(NSString *)placementName adFormat:(SharedAdFormat *)adFormat cappingType:(SharedCappingType *)cappingType cappingConfig:(id<SharedICappingConfigProvider>)cappingConfig __attribute__((swift_name("addConfig(placementName:adFormat:cappingType:cappingConfig:)")));
- (void)updateCappingOnShowPlacementName:(NSString *)placementName adFormat:(SharedAdFormat *)adFormat __attribute__((swift_name("updateCappingOnShow(placementName:adFormat:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PlacementCappingService")))
@interface SharedPlacementCappingService : SharedBase <SharedIPlacementCappingService, SharedIPlacementCappingServiceEditor>
- (instancetype)initWithCappingService:(SharedCappingService *)cappingService deliveryHandler:(SharedDeliveryHandler *)deliveryHandler __attribute__((swift_name("init(cappingService:deliveryHandler:)"))) __attribute__((objc_designated_initializer));

/**
 * @note annotations
 *   kotlin.jvm.Synchronized
*/
- (id _Nullable)addConfigPlacementName:(NSString *)placementName adFormat:(SharedAdFormat *)adFormat cappingType:(SharedCappingType *)cappingType cappingConfig:(id<SharedICappingConfigProvider>)cappingConfig __attribute__((swift_name("addConfig(placementName:adFormat:cappingType:cappingConfig:)")));

/**
 * @note annotations
 *   kotlin.jvm.Synchronized
*/
- (SharedCappingStatus *)cappingStatusPlacementName:(NSString *)placementName adFormat:(SharedAdFormat *)adFormat __attribute__((swift_name("cappingStatus(placementName:adFormat:)")));

/**
 * @note annotations
 *   kotlin.jvm.Synchronized
*/
- (void)updateCappingOnShowPlacementName:(NSString *)placementName adFormat:(SharedAdFormat *)adFormat __attribute__((swift_name("updateCappingOnShow(placementName:adFormat:)")));
@end

__attribute__((swift_name("ICappingConfigProvider")))
@protocol SharedICappingConfigProvider
@required
- (id _Nullable)createDeliveryValidatedConfig __attribute__((swift_name("createDeliveryValidatedConfig()")));
- (id _Nullable)createPacingValidatedConfig __attribute__((swift_name("createPacingValidatedConfig()")));
- (id _Nullable)createShowCountValidatedConfig __attribute__((swift_name("createShowCountValidatedConfig()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CappingConfigProvider")))
@interface SharedCappingConfigProvider : SharedBase <SharedICappingConfigProvider>
- (instancetype)initWithEnabled:(SharedBoolean * _Nullable)enabled limit:(SharedInt * _Nullable)limit unit:(SharedCappingTimeUnit * _Nullable)unit __attribute__((swift_name("init(enabled:limit:unit:)"))) __attribute__((objc_designated_initializer));
- (id _Nullable)createDeliveryValidatedConfig __attribute__((swift_name("createDeliveryValidatedConfig()")));
- (id _Nullable)createPacingValidatedConfig __attribute__((swift_name("createPacingValidatedConfig()")));
- (id _Nullable)createShowCountValidatedConfig __attribute__((swift_name("createShowCountValidatedConfig()")));
@property (readonly) SharedBoolean * _Nullable enabled __attribute__((swift_name("enabled")));
@property (readonly) SharedInt * _Nullable limit __attribute__((swift_name("limit")));
@property (readonly) SharedCappingTimeUnit * _Nullable unit __attribute__((swift_name("unit")));
@end

__attribute__((swift_name("ICappingConfigValidator")))
@protocol SharedICappingConfigValidator
@required
- (id _Nullable)validateConfig __attribute__((swift_name("validateConfig()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CappingConfigValidator")))
@interface SharedCappingConfigValidator : SharedBase <SharedICappingConfigValidator>
- (instancetype)initWithEnabled:(SharedBoolean * _Nullable)enabled limit:(SharedInt * _Nullable)limit unit:(SharedCappingTimeUnit * _Nullable)unit __attribute__((swift_name("init(enabled:limit:unit:)"))) __attribute__((objc_designated_initializer));
- (id _Nullable)validateConfig __attribute__((swift_name("validateConfig()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CappingType")))
@interface SharedCappingType : SharedKotlinEnum<SharedCappingType *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) SharedCappingType *pacing __attribute__((swift_name("pacing")));
@property (class, readonly) SharedCappingType *showcount __attribute__((swift_name("showcount")));
@property (class, readonly) SharedCappingType *delivery __attribute__((swift_name("delivery")));
+ (SharedKotlinArray<SharedCappingType *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<SharedCappingType *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DeliveryConfigValidator")))
@interface SharedDeliveryConfigValidator : SharedBase <SharedICappingConfigValidator>
- (instancetype)initWithEnabled:(SharedBoolean * _Nullable)enabled __attribute__((swift_name("init(enabled:)"))) __attribute__((objc_designated_initializer));
- (id _Nullable)validateConfig __attribute__((swift_name("validateConfig()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DeliveryCappingConfig")))
@interface SharedDeliveryCappingConfig : SharedBase
- (instancetype)initWithEnabled:(BOOL)enabled __attribute__((swift_name("init(enabled:)"))) __attribute__((objc_designated_initializer));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) BOOL enabled __attribute__((swift_name("enabled")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DeliveryHandler")))
@interface SharedDeliveryHandler : SharedBase <SharedICappingService, SharedICappingServiceEditor>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (id _Nullable)addConfigIdentifier:(NSString *)identifier cappingType:(SharedCappingType *)cappingType cappingConfig:(id<SharedICappingConfigProvider>)cappingConfig __attribute__((swift_name("addConfig(identifier:cappingType:cappingConfig:)")));
- (SharedCappingStatus *)cappingStatusIdentifier:(NSString *)identifier __attribute__((swift_name("cappingStatus(identifier:)")));
- (void)updateCappingOnShowIdentifier:(NSString *)identifier __attribute__((swift_name("updateCappingOnShow(identifier:)")));
@end

__attribute__((swift_name("IPacingDataRepository")))
@protocol SharedIPacingDataRepository
@required
- (SharedLong * _Nullable)getLastShowTimeIdentifier:(NSString *)identifier __attribute__((swift_name("getLastShowTime(identifier:)")));
- (void)setLastShowTimeTime:(int64_t)time identifier:(NSString *)identifier __attribute__((swift_name("setLastShowTime(time:identifier:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PacingCappingConfig")))
@interface SharedPacingCappingConfig : SharedBase
- (instancetype)initWithTimeInterval:(int64_t)timeInterval unit:(SharedCappingTimeUnit *)unit __attribute__((swift_name("init(timeInterval:unit:)"))) __attribute__((objc_designated_initializer));
- (int64_t)timeInterval __attribute__((swift_name("timeInterval()")));
- (NSString *)description __attribute__((swift_name("description()")));
- (SharedCappingTimeUnit *)unit __attribute__((swift_name("unit()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PacingCappingHandler")))
@interface SharedPacingCappingHandler : SharedBase <SharedICappingService, SharedICappingServiceEditor>
- (instancetype)initWithCurrentTimeProvider:(id<SharedCurrentTimeProvider>)currentTimeProvider repository:(id<SharedIPacingDataRepository>)repository __attribute__((swift_name("init(currentTimeProvider:repository:)"))) __attribute__((objc_designated_initializer));
- (id _Nullable)addConfigIdentifier:(NSString *)identifier cappingType:(SharedCappingType *)cappingType cappingConfig:(id<SharedICappingConfigProvider>)cappingConfig __attribute__((swift_name("addConfig(identifier:cappingType:cappingConfig:)")));
- (SharedCappingStatus *)cappingStatusIdentifier:(NSString *)identifier __attribute__((swift_name("cappingStatus(identifier:)")));
- (void)updateCappingOnShowIdentifier:(NSString *)identifier __attribute__((swift_name("updateCappingOnShow(identifier:)")));
@property (readonly) SharedMutableDictionary<NSString *, SharedPacingCappingConfig *> *configs __attribute__((swift_name("configs")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PacingDataRepository")))
@interface SharedPacingDataRepository : SharedBase <SharedIPacingDataRepository>
- (instancetype)initWithStorage:(id<SharedDataStorage>)storage __attribute__((swift_name("init(storage:)"))) __attribute__((objc_designated_initializer));
- (SharedLong * _Nullable)getLastShowTimeIdentifier:(NSString *)identifier __attribute__((swift_name("getLastShowTime(identifier:)")));
- (void)setLastShowTimeTime:(int64_t)time identifier:(NSString *)identifier __attribute__((swift_name("setLastShowTime(time:identifier:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PlacementIdentifierliron")))
@interface SharedPlacementIdentifierliron : SharedBase
- (instancetype)initWithPlacementName:(NSString *)placementName adFormat:(SharedAdFormat *)adFormat __attribute__((swift_name("init(placementName:adFormat:)"))) __attribute__((objc_designated_initializer));
- (NSString *)value __attribute__((swift_name("value()")));
@end

__attribute__((swift_name("IShowCountDataRepository")))
@protocol SharedIShowCountDataRepository
@required
- (int32_t)getCurrentNumberOfShowsIdentifier:(NSString *)identifier __attribute__((swift_name("getCurrentNumberOfShows(identifier:)")));
- (SharedLong * _Nullable)getTimeThresholdIdentifier:(NSString *)identifier __attribute__((swift_name("getTimeThreshold(identifier:)")));
- (void)setCurrentNumberOfShowsCount:(int32_t)count identifier:(NSString *)identifier __attribute__((swift_name("setCurrentNumberOfShows(count:identifier:)")));
- (void)setTimeThresholdThreshold:(int64_t)threshold identifier:(NSString *)identifier __attribute__((swift_name("setTimeThreshold(threshold:identifier:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ShowCountCappingConfig")))
@interface SharedShowCountCappingConfig : SharedBase
- (instancetype)initWithMaxImpressions:(int32_t)maxImpressions unit:(SharedCappingTimeUnit *)unit __attribute__((swift_name("init(maxImpressions:unit:)"))) __attribute__((objc_designated_initializer));
- (int32_t)maxImpressions __attribute__((swift_name("maxImpressions()")));
- (NSString *)description __attribute__((swift_name("description()")));
- (SharedCappingTimeUnit *)unit __attribute__((swift_name("unit()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ShowCountHandler")))
@interface SharedShowCountHandler : SharedBase <SharedICappingService, SharedICappingServiceEditor>
- (instancetype)initWithCurrentTimeProvider:(id<SharedCurrentTimeProvider>)currentTimeProvider serviceDataRepository:(id<SharedIShowCountDataRepository>)serviceDataRepository __attribute__((swift_name("init(currentTimeProvider:serviceDataRepository:)"))) __attribute__((objc_designated_initializer));
- (id _Nullable)addConfigIdentifier:(NSString *)identifier cappingType:(SharedCappingType *)cappingType cappingConfig:(id<SharedICappingConfigProvider>)cappingConfig __attribute__((swift_name("addConfig(identifier:cappingType:cappingConfig:)")));
- (SharedCappingStatus *)cappingStatusIdentifier:(NSString *)identifier __attribute__((swift_name("cappingStatus(identifier:)")));
- (void)updateCappingOnShowIdentifier:(NSString *)identifier __attribute__((swift_name("updateCappingOnShow(identifier:)")));
@property (readonly) SharedMutableDictionary<NSString *, SharedShowCountCappingConfig *> *configs __attribute__((swift_name("configs")));
@end

__attribute__((swift_name("PacingCappingStorage")))
@protocol SharedPacingCappingStorage
@required
- (SharedLong * _Nullable)getLastShowTimeIdentifier:(NSString *)identifier __attribute__((swift_name("getLastShowTime(identifier:)")));
- (void)setLastShowTimeTime:(int64_t)time identifier:(NSString *)identifier __attribute__((swift_name("setLastShowTime(time:identifier:)")));
@end

__attribute__((swift_name("ShowCountCappingStorage")))
@protocol SharedShowCountCappingStorage
@required
- (SharedInt * _Nullable)getCurrentNumberOfShowsIdentifier_:(NSString *)identifier __attribute__((swift_name("getCurrentNumberOfShows(identifier_:)")));
- (SharedLong * _Nullable)getTimeThresholdIdentifier:(NSString *)identifier __attribute__((swift_name("getTimeThreshold(identifier:)")));
- (void)setCurrentNumberOfShowsCount:(int32_t)count identifier:(NSString *)identifier __attribute__((swift_name("setCurrentNumberOfShows(count:identifier:)")));
- (void)setTimeThresholdTime:(int64_t)time identifier:(NSString *)identifier __attribute__((swift_name("setTimeThreshold(time:identifier:)")));
@end

__attribute__((swift_name("IRewardService")))
@protocol SharedIRewardService
@required
- (SharedLevelPlayReward * _Nullable)getRewardPlacement:(NSString * _Nullable)placement adUnitId:(NSString *)adUnitId __attribute__((swift_name("getReward(placement:adUnitId:)")));
@end

__attribute__((swift_name("IRewardServiceEditor")))
@protocol SharedIRewardServiceEditor
@required
- (void)addAdUnitIdConfigAdUnitId:(NSString *)adUnitId rewardName:(NSString *)rewardName rewardAmount:(int32_t)rewardAmount __attribute__((swift_name("addAdUnitIdConfig(adUnitId:rewardName:rewardAmount:)")));
- (void)addPlacementConfigPlacement:(NSString *)placement rewardName:(NSString *)rewardName rewardAmount:(int32_t)rewardAmount __attribute__((swift_name("addPlacementConfig(placement:rewardName:rewardAmount:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LevelPlayReward")))
@interface SharedLevelPlayReward : SharedBase
- (instancetype)initWithName:(NSString *)name amount:(int32_t)amount __attribute__((swift_name("init(name:amount:)"))) __attribute__((objc_designated_initializer));
- (SharedLevelPlayReward *)doCopyName:(NSString *)name amount:(int32_t)amount __attribute__((swift_name("doCopy(name:amount:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t amount __attribute__((swift_name("amount")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RewardService")))
@interface SharedRewardService : SharedBase <SharedIRewardService, SharedIRewardServiceEditor>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)addAdUnitIdConfigAdUnitId:(NSString *)adUnitId rewardName:(NSString *)rewardName rewardAmount:(int32_t)rewardAmount __attribute__((swift_name("addAdUnitIdConfig(adUnitId:rewardName:rewardAmount:)")));
- (void)addPlacementConfigPlacement:(NSString *)placement rewardName:(NSString *)rewardName rewardAmount:(int32_t)rewardAmount __attribute__((swift_name("addPlacementConfig(placement:rewardName:rewardAmount:)")));
- (SharedLevelPlayReward * _Nullable)getRewardPlacement:(NSString * _Nullable)placement adUnitId:(NSString *)adUnitId __attribute__((swift_name("getReward(placement:adUnitId:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Platform_iosKt")))
@interface SharedPlatform_iosKt : SharedBase
+ (id<SharedPlatform>)getPlatform __attribute__((swift_name("getPlatform()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinEnumCompanion")))
@interface SharedKotlinEnumCompanion : SharedBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) SharedKotlinEnumCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinArray")))
@interface SharedKotlinArray<T> : SharedBase
+ (instancetype)arrayWithSize:(int32_t)size init:(T _Nullable (^)(SharedInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (T _Nullable)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (id<SharedKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(T _Nullable)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

__attribute__((swift_name("KotlinIterator")))
@protocol SharedKotlinIterator
@required
- (BOOL)hasNext __attribute__((swift_name("hasNext()")));
- (id _Nullable)next __attribute__((swift_name("next()")));
@end

#pragma pop_macro("_Nullable_result")
#pragma clang diagnostic pop
NS_ASSUME_NONNULL_END
