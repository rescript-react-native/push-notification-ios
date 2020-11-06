# `@reason-react-native/push-notification-ios`

[![Build Status](https://github.com/reason-react-native/push-notification-ios/workflows/Build/badge.svg)](https://github.com/reason-react-native/push-notification-ios/actions)
[![Version](https://img.shields.io/npm/v/@reason-react-native/push-notification-ios.svg)](https://www.npmjs.com/@reason-react-native/push-notification-ios)
[![Chat](https://img.shields.io/discord/235176658175262720.svg?logo=discord&colorb=blue)](https://reasonml-community.github.io/reason-react-native/discord/)

[ReScript](https://rescript-lang.org) / [Reason](https://reasonml.github.io) bindings for
[`@react-native-community/react-native-push-notification-ios`](https://github.com/react-native-community/react-native-push-notification-ios).

Exposed as `ReactNativePushNotificationIOS` module.

`@reason-react-native/push-notification-ios` X.y.\* means it's compatible with
`@react-native-community/react-native-push-notification-ios` X.y.\*

## Installation

When
[`@react-native-community/react-native-push-notification-ios`](https://github.com/react-native-community/react-native-push-notification-ios)
is properly installed & configured by following their installation instructions,
you can install the bindings:

```console
npm install @reason-react-native/push-notification-ios
# or
yarn add @reason-react-native/push-notification-ios
```

`@reason-react-native/push-notification-ios` should be added to
`bs-dependencies` in your `bsconfig.json`:

```diff
{
  //...
  "bs-dependencies": [
    "reason-react",
    "reason-react-native",
    // ...
+    "@reason-react-native/push-notification-ios"
  ],
  //...
}
```

## Usage

### Types

#### `ReactNativePushNotificationIOS.Notification.t`

```reason
  type t; // abstract type
```

#### `ReactNativePushNotificationIOS.localNotification`

```reason
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

```reason
type deliveredNotification = {
  identifier: string
  date: option(string)
  title: option(string)
  body: option(string)
  category: option(string)
  threadId: option(string)
  userInfo: option(Js.Json.t),
};
```

#### `ReactNativePushNotificationIOS.formattedLocalNotification`

```reason
type formattedLocalNotification = {
  fireDate: option(string),
  alertAction: option(string),
  alertTitle: option(string),
  alertBody: option(string),
  applicationIconBadgeNumber: option(int),
  category: option(string),
  repeatInterval: option(string),
  soundName: option(string),
  userInfo: option(Js.Json.t),
};
```

#### `ReactNativePushNotificationIOS.registrationError`

```reason
type registrationError('a) = {
  message: string,
  code: int,
  details: Js.t('a),
};
```

#### `ReactNativePushNotificationIOS.permissions`

```reason
type permissions = {
  alert: bool,
  badge: bool,
  sound: bool,
  lockScreen: bool,
  notificationCenter: bool,
};
```

#### `ReactNativePushNotificationIOS.requestPermissionsOptions`

```reason
type requestPermissionsOptions;
[@bs.obj]
external requestPermissionsOptions:
  (~alert: bool=?, ~badge: bool=?, ~sound: bool=?, unit) =>
  requestPermissionsOptions =
  "";
```

#### `ReactNativePushNotificationIOS.fetchResult`

```reason
type fetchResult;
[@bs.obj]
external fetchResult:
  (~_NewData: string=?, ~_NoData: string=?, ~_ResultFailed: string=?, unit) =>
  fetchResult =
  "";
```

### Methods

#### `ReactNativePushNotificationIOS.Notification.getAlert`

```reason
Notification.t => option(Js.Json.t)
```

#### `ReactNativePushNotificationIOS.Notification.getTitle`

```reason
Notification.t => option(string)
```

#### `ReactNativePushNotificationIOS.Notification.getMessage`

```reason
Notification.t => option(Js.Json.t)
```

#### `ReactNativePushNotificationIOS.Notification.getSound`

```reason
Notification.t => option(string)
```

#### `ReactNativePushNotificationIOS.Notification.getCategory`

```reason
Notification.t => option(string)
```

#### `ReactNativePushNotificationIOS.Notification.getContentAvailable`

```reason
Notification.t => bool
```

#### `ReactNativePushNotificationIOS.Notification.getBadgeCount`

```reason
Notification.t => option(int)
```

#### `ReactNativePushNotificationIOS.Notification.getData`

```reason
Notification.t => option(Js.Json.t)
```

#### `ReactNativePushNotificationIOS.Notification.getThreadID`

```reason
Notification.t => option(string)
```

#### `ReactNativePushNotificationIOS.presentLocalNotification`

```reason
localNotification => unit
```

#### `ReactNativePushNotificationIOS.scheduleLocalNotification`

```reason
localNotification => unit
```

#### `ReactNativePushNotificationIOS.cancelAllLocalNotifications`

```reason
unit => unit
```

#### `ReactNativePushNotificationIOS.removeAllDeliveredNotifications`

```reason
unit => unit
```

#### `ReactNativePushNotificationIOS.getDeliveredNotifications`

```reason
(array(deliveredNotification) => unit)
```

#### `ReactNativePushNotificationIOS.removeDeliveredNotifications`

```reason
(~identifiers: array(string)) => unit
```

#### `ReactNativePushNotificationIOS.setApplicationIconBadgeNumber`

```reason
int => unit
```

#### `ReactNativePushNotificationIOS.getApplicationIconBadgeNumber`

```reason
(int => unit) => unit
```

#### `ReactNativePushNotificationIOS.cancelLocalNotifications`

```reason
unit => unit
```

#### `ReactNativePushNotificationIOS.cancelLocalNotificationsWithUserInfo`

```reason
Js.Json.t => unit
```

#### `ReactNativePushNotificationIOS.getScheduledLocalNotifications`

```reason
(array(formattedLocalNotification) => unit) => unit
```

#### `ReactNativePushNotificationIOS.addEventListener`

```reason
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

```reason
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

```reason
unit => Js.Promise.t(permissions)
```

#### `ReactNativePushNotificationIOS.requestPermissionsWithOptions`

```reason
requestPermissionsOptions => Js.Promise.t(permissions)
```

#### `ReactNativePushNotificationIOS.abandonPermissions`

```reason
unit => unit
```

#### `ReactNativePushNotificationIOS.checkPermissions`

```reason
(unit => permissions) => unit
```

#### `ReactNativePushNotificationIOS.finish`

```reason
fetchResult => unit
```

#### `ReactNativePushNotificationIOS.getInitialNotification`

```reason
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
