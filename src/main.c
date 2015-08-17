#include <pebble.h>

AppFocusHandler on_app_focus;
AccelDataHandler on_movement;
WakeupHandler on_wakeup;
AppWorkerMessageHandler on_worker;
ClickConfigProvider config_provider;
  
Window *my_window;
TextLayer *text_layer;

void down_single_click_handler(ClickRecognizerRef recognizer, void *context) {
  Window *window = (Window *)context;
}
void select_single_click_handler(ClickRecognizerRef recognizer, void *context) {
  Window *window = (Window *)context;
}

void select_multi_click_handler(ClickRecognizerRef recognizer, void *context) {
  Window *window = (Window *)context;
  const uint16_t count = click_number_of_clicks_counted(recognizer);
}

void select_long_click_handler(ClickRecognizerRef recognizer, void *context) {
  Window *window = (Window *)context;
}

void select_long_click_release_handler(ClickRecognizerRef recognizer, void *context) {
  Window *window = (Window *)context;
}

void config_provider(Window *window) {
 // single click / repeat-on-hold config:
  //window_single_click_subscribe(BUTTON_ID_DOWN, down_single_click_handler);
  //window_single_repeating_click_subscribe(BUTTON_ID_SELECT, 1000, select_single_click_handler);

  // multi click config:
  //window_multi_click_subscribe(BUTTON_ID_SELECT, 2, 10, 0, true, select_multi_click_handler);

  // long click config:
  //window_long_click_subscribe(BUTTON_ID_SELECT, 700, select_long_click_handler, select_long_click_release_handler);
}

void on_app_focus(bool in_focus) {
  
}

// app_worker_launch();
// app_worker_send_message(uint8_t type, AppWorkerMessage * data);
// app_worker_kill();
void on_worker(uint16_t type, AppWorkerMessage *data) {
  
}

void on_wakeup(WakeupId wakeup_id, int32_t cookie) {
  
}

void on_movement(AccelData *data, uint32_t num_samples) {
  
}
  
void launchWorker() {
  AppWorkerResult result = app_worker_launch();
}

void on_launch() {
  switch(launch_reason()) {
  case APP_LAUNCH_SYSTEM:
  // App launched by the system.
    break;
  case APP_LAUNCH_USER:
  // App launched by user selection in launcher menu.
    break;
  case APP_LAUNCH_PHONE:
  // App launched by mobile or companion app.
    break;
  case APP_LAUNCH_WAKEUP:
  // App launched by wakeup event.
    bool wakeup_get_launch_event(WakeupId * wakeup_id, int32_t * cookie);
    break;
  case APP_LAUNCH_WORKER:
  // App launched by worker calling worker_launch_app()
    break;
  case APP_LAUNCH_QUICK_LAUNCH:
  // App launched by user using quick launch.
    break;
  case APP_LAUNCH_TIMELINE_ACTION:
  // App launched by user opening it from a pin.
  }

}

void handle_init(void) {
  my_window = window_create();

  // Setup any event handlers
  app_focus_service_subscribe(on_app_focus);
  wakeup_service_subscribe(on_wakeup);
  app_worker_message_subscribe(on_worker);
  window_set_click_config_provider(my_window, config_provider);
//  accel_service_set_sampling_rate(ACCEL_SAMPLING_10HZ)
//  accel_data_service_subscribe(25, on_movement);
    
  text_layer = text_layer_create(GRect(0, 0, 144, 20));
  window_stack_push(my_window, true);
}


void probably_not_this() {
  // Check to see if the worker is currently active
  bool running = app_worker_is_running();
    
  // App is opened for the first time
  //     o Display Welcome Message, Invite to set alerts.
  //     o Set app to wake up at the time of the next alert.
  //     o Start background worker
  //     o Check background worker is running
  //     o Trigger to go to sleep mode
  // App is woken by wakeup API for alarm time
  //     o Check background worker is running
  //     o Start if not
  //     o Display "Pill Reminder"
  //     o Gently buzz
  //     o Trigger to check for movement
  //     o Set app to wake up in 15 mins
  //     o Go back to sleep
  // App is woken by wakeup API for activity check
  //     o See how active we've been
  //     o If we've been active, buzz and display pill reminder
  //     o Go back to sleep for 15 mins
  // App is woken by wakeup API for second time
  //     o Send a text message/notification
  // User presses select
  //     o Put background worker to sleep
  //     o Thank the user
  //     o Notify carer
  //     o wakeup_cancel_all()
  //     o Set wakeup api to wake for next alarm.
  //       WakeupId wakeup_schedule(time_t timestamp, int32_t cookie, bool notify_if_missed)
}

void handle_deinit(void) {
  text_layer_destroy(text_layer);
  window_destroy(my_window);
  wakeup_service_unsubscribe();
  app_focus_service_unsubscribe();
  app_worker_message_unsubscribe();
}

int main(void) {
  handle_init();
  app_event_loop();
  handle_deinit();
}
