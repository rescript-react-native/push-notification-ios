# `@reason-react-native/react-native-push-notification-ios`

[![Build Status](https://github.com/reason-react-native/react-native-push-notification-ios/workflows/Build/badge.svg)](https://github.com/reason-react-native/react-native-push-notification-ios/actions)
[![Version](https://img.shields.io/npm/v/@reason-react-native/react-native-push-notification-ios.svg)](https://www.npmjs.com/@reason-react-native/react-native-push-notification-ios)
[![Chat](https://img.shields.io/discord/235176658175262720.svg?logo=discord&colorb=blue)](https://reasonml-community.github.io/reason-react-native/discord/)

[ReasonML](https://reasonml.github.io) /
[BuckleScript](https://bucklescript.github.io) bindings for
[`@react-native-community/react-native-push-notification-ios`](https://github.com/react-native-community/react-native-push-notification-ios).

Exposed as `ReactNativePushNotificationIOS` module.

`@reason-react-native/react-native-push-notification-ios` X.y._ means it's
compatible with `@react-native-community/react-native-push-notification-ios`
X.y._

## Installation

When
[`@react-native-community/react-native-push-notification-ios`](https://github.com/react-native-community/react-native-push-notification-ios)
is properly installed & configured by following their installation instructions,
you can install the bindings:

```console
npm install @reason-react-native/react-native-push-notification-ios
# or
yarn add @reason-react-native/react-native-push-notification-ios
```

`@reason-react-native/react-native-push-notification-ios` should be added to
`bs-dependencies` in your `bsconfig.json`. Something like

```diff
{
  //...
  "bs-dependencies": [
    "reason-react",
    "reason-react-native",
    // ...
+    "@reason-react-native/react-native-push-notification-ios"
  ],
  //...
}
```

## Usage

### Types

#### `ReactNativePushNotificationIOS.Notification.t`

```re
  type t; // abstract type
```

#### `ReactNativePushNotificationIOS.localNotification`

```re
type localNotification;

[@bs.obj]
external localNotification:
  (
    ~alertBody: string=?,
    ~alertTitle: string=?,
    ~alertAction: string=?,
    ~soundName: string=?,
    ~isSilent: bool=?,
    ~category: string=?,
    ~userInfo: Js.Json.t=?,
    ~applicationIconBadgeNumber: int=?,
    ~fireDate: Js.Date.t=?,
    ~repeatInterval: [@bs.string] [
                       | `minute
                       | `hour
                       | `day
                       | `week
                       | `month
                       | `year
                     ]
                       =?,
    unit
  ) =>
  localNotification =
  "";
```

#### `ReactNativePushNotificationIOS.deliveredNotification`

```re
type deliveredNotification = {
  .
  "identifier": string,
  "date": Js.Nullable.t(string),
  "title": Js.Nullable.t(string),
  "body": Js.Nullable.t(string),
  "category": Js.Nullable.t(string),
  "thread-id": Js.Nullable.t(string),
  "userInfo": Js.Nullable.t(Js.Json.t),
};
```

#### `ReactNativePushNotificationIOS.formattedLocalNotification`

```re
type formattedLocalNotification = {
  .
  "fireDate": Js.Nullable.t(string),
  "alertAction": Js.Nullable.t(string),
  "alertBody": Js.Nullable.t(string),
  "applicationIconBadgeNumber": Js.Nullable.t(int),
  "category": Js.Nullable.t(string),
  "soundName": Js.Nullable.t(string),
  "userInfo": Js.Nullable.t(Js.Json.t),
};
```

#### `ReactNativePushNotificationIOS.registrationError`

```re
type registrationError('a) = {
  .
  "message": string,
  "code": int,
  "details": Js.t('a),
};
```

#### `ReactNativePushNotificationIOS.permissions`

```re
type permissions = {
  .
  "alert": bool,
  "badge": bool,
  "sound": bool,
};
```

#### `ReactNativePushNotificationIOS.requestPermissionsOptions`

```re
type requestPermissionsOptions;
[@bs.obj]
external requestPermissionsOptions:
  (~alert: bool=?, ~badge: bool=?, ~sound: bool=?, unit) =>
  requestPermissionsOptions =
  "";
```

#### `ReactNativePushNotificationIOS.fetchResult`

```re
type fetchResult;
[@bs.obj]
external fetchResult:
  (~_NewData: string=?, ~_NoData: string=?, ~_ResultFailed: string=?, unit) =>
  fetchResult =
  "";
```

### Methods

#### `ReactNativePushNotificationIOS.Notification.getAlert`

```re
Notification.t => option(Js.Json.t)
```

#### `ReactNativePushNotificationIOS.Notification.getMessage`

```re
Notification.t => option(Js.Json.t)
```

#### `ReactNativePushNotificationIOS.Notification.getSound`

```re
Notification.t => option(string)
```

#### `ReactNativePushNotificationIOS.Notification.getCategory`

```re
Notification.t => option(string)
```

#### `ReactNativePushNotificationIOS.Notification.getContentAvailable`

```re
Notification.t => bool
```

#### `ReactNativePushNotificationIOS.Notification.getBadgeCount`

```re
Notification.t => option(int)
```

#### `ReactNativePushNotificationIOS.Notification.getData`

```re
Notification.t => option(Js.Json.t)
```

#### `ReactNativePushNotificationIOS.Notification.getThreadID`

```re
Notification.t => option(string)
```

#### `ReactNativePushNotificationIOS.presentLocalNotification`

```re
localNotification => unit
```

#### `ReactNativePushNotificationIOS.scheduleLocalNotification`

```re
localNotification => unit
```

#### `ReactNativePushNotificationIOS.cancelAllLocalNotifications`

```re
unit => unit
```

#### `ReactNativePushNotificationIOS.removeAllDeliveredNotifications`

```re
unit => unit
```

#### `ReactNativePushNotificationIOS.getDeliveredNotifications`

```re
(array(deliveredNotification) => unit)
```

#### `ReactNativePushNotificationIOS.removeDeliveredNotifications`

```re
(~identifiers: array(string)) => unit
```

#### `ReactNativePushNotificationIOS.setApplicationIconBadgeNumber`

```re
int => unit
```

#### `ReactNativePushNotificationIOS.getApplicationIconBadgeNumber`

```re
(int => unit) => unit
```

#### `ReactNativePushNotificationIOS.cancelLocalNotifications`

```re
unit => unit
```

#### `ReactNativePushNotificationIOS.cancelLocalNotificationsWithUserInfo`

```re
Js.Json.t => unit
```

#### `ReactNativePushNotificationIOS.getScheduledLocalNotifications`

```re
(array(formattedLocalNotification) => unit) => unit
```

#### `ReactNativePushNotificationIOS.addEventListener`

```re
  (
  [@bs.string]
  [
    | `notification(Notification.t => unit)
    | `localNotification(Notification.t => unit)
    | `register((~deviceToken: string) => unit)
    | `registrationError(registrationError('a) => unit)
  ]
  ) =>
  unit
```

#### `ReactNativePushNotificationIOS.removeEventListener`

```re
(
  [@bs.string]
  [
    | `notification(Notification.t => unit)
    | `localNotification(Notification.t => unit)
    | `register((~deviceToken: string) => unit)
    | `registrationError(registrationError('a) => unit)
  ]
  ) =>
  unit
```

#### `ReactNativePushNotificationIOS.requestPermissions`

```re
unit => Js.Promise.t(permissions)
```

#### `ReactNativePushNotificationIOS.requestPermissionsWithOptions`

```re
requestPermissionsOptions => Js.Promise.t(permissions)
```

#### `ReactNativePushNotificationIOS.abandonPermissions`

```re
unit => unit
```

#### `ReactNativePushNotificationIOS.checkPermissions`

```re
(unit => permissions) => unit
```

#### `ReactNativePushNotificationIOS.finish`

```re
fetchResult => unit
```

#### `ReactNativePushNotificationIOS.getInitialNotification`

```re
unit => Js.Promise.t(Js.Nullable.t(Notification.t))
```

## Changelog

Check the [changelog](./CHANGELOG.md) for more informations about recent
releases.

---

## Contribute

Read the
[contribution guidelines](https://github.com/reason-react-native/.github/blob/master/CONTRIBUTING.md)
before contributing.

## Code of Conduct

We want this community to be friendly and respectful to each other. Please read
[our full code of conduct](https://github.com/reason-react-native/.github/blob/master/CODE_OF_CONDUCT.md)
so that you can understand what actions will and will not be tolerated.
